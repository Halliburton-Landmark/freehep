package hep.io.root.core;

import hep.io.root.*;
import hep.io.root.interfaces.*;

import org.apache.bcel.*;
import org.apache.bcel.classfile.*;
import org.apache.bcel.generic.*;

import java.util.*;

/**
 *
 * @author tonyj
 * @version $Id: HollowBuilder.java,v 1.4 2005/08/10 00:56:30 tonyj Exp $
 */
public class HollowBuilder implements ClassBuilder, Constants
{
   private static boolean debugRoot = System.getProperty("debugRoot") != null;
   private static NameMangler nameMangler = NameMangler.instance();
   private static final Object SUBOBJECT = new Object();
   private Map lMap;
   private String prefix;
   private TBranch branch;
   private boolean hasSubIndex = false;
   
   public HollowBuilder(TBranch branch)
   {
      this.branch = branch;
   }
   
   public HollowBuilder(TBranch branch, boolean hasSubIndex)
   {
      this.branch = branch;
      this.hasSubIndex = hasSubIndex;
   }
   
   public HollowBuilder(TBranch branch, String prefix)
   {
      this.branch = branch;
      this.prefix = prefix;
   }
   
   public HollowBuilder(TBranch branch, String prefix, boolean hasSubIndex)
   {
      this.branch = branch;
      this.prefix = prefix;
      this.hasSubIndex = hasSubIndex;
   }
   
   public String getStem()
   {
      return "hep.io.root.hollow";
   }
   
   public JavaClass build(GenericRootClass klass)
   {
      String className = "hep.io.root.hollow." + klass.getClassName();
      ClassGen cg = new ClassGen(className, "hep/io/root/core/Hollow", "<generated>", ACC_PUBLIC | ACC_SUPER, new String[]
      {
         nameMangler.mangleClass(klass.getClassName())
      });
      ConstantPoolGen cp = cg.getConstantPool();
      InstructionList il = new InstructionList();
      InstructionFactory factory = new InstructionFactory(cg);
      
      cg.addEmptyConstructor(ACC_PUBLIC);
      
      // Build the complete list of superclasses
      List sup = new ArrayList();
      RootClass[] superClasses = klass.getSuperClasses();
      iterativelyAdd(sup, superClasses);
      sup.add(klass);
      
      // Loop over all the leafs, and build a hashtable from name->leaf
      Map nameMap = new HashMap();
      TObjArray branches = branch.getBranches();
      for (Iterator j = branches.iterator(); j.hasNext();)
      {
         TBranch br = (TBranch) j.next();
         TObjArray leaves = br.getLeaves();
         branch: for (Iterator i = leaves.iterator(); i.hasNext();)
         {
            Object leaf = i.next();
            String name = ((TLeaf) leaf).getName();
            int pos = name.indexOf('[');
            if (pos > 0)
               name = name.substring(0, pos);
            if (name.endsWith("_"))
               name = name.substring(0, name.length() - 1);
            if (prefix != null)
            {
               if (!name.startsWith(prefix))
                  continue;
               name = name.substring(prefix.length());
            }
            pos = name.indexOf('.');
            if (pos > 0)
            {
               name = name.substring(0, pos);
               leaf = SUBOBJECT;
            }
            nameMap.put(name, leaf);
         }
      }
      lMap = new HashMap();
      
      // Loop over the members and try to find the matching leaf
      for (Iterator j = sup.iterator(); j.hasNext();)
      {
         RootClass k = (RootClass) j.next();
         RootMember[] members = k.getMembers();
         for (int i = 0; i < members.length; i++)
         {
            BasicMember member = (BasicMember) members[i];
            String name = member.getName();
            if (name.endsWith("_"))
               name = name.substring(0, name.length() - 1);
            
            Object leaf = nameMap.remove(name);
            if (leaf == null)
            {
               if (debugRoot) System.err.println("Warning: no leaf for " + member.getName());
            }
            else
            {
               lMap.put(member, leaf);
            }
         }
      }
      
      // Check for any left over leafs
      if (debugRoot)
      {
         for (Iterator i = nameMap.keySet().iterator(); i.hasNext();)
         {
            System.err.println("Warning: unused leaf " + i.next());
         }
      }
      
      // Generate the fields
      for (Iterator i = sup.iterator(); i.hasNext();)
         generateFields((RootClass) i.next(), cp, cg);
      
      // Generate the accessor methods
      for (Iterator i = sup.iterator(); i.hasNext();)
         generateMethods((RootClass) i.next(), cp, il, factory, cg, className);
      
      return cg.getJavaClass();
   }
   
   public void populateStatics(Class hollowClass, RootClassFactory factory)
   {
      try
      {
         // Loop over the leaves
         for (Iterator i = lMap.entrySet().iterator(); i.hasNext();)
         {
            Map.Entry entry = (Map.Entry) i.next();
            BasicMember member = (BasicMember) entry.getKey();
            Object l = entry.getValue();
            if (l == SUBOBJECT)
            {
               HollowBuilder builder = new HollowBuilder(branch, member.getName() + ".");
               String name = "hep.io.root.hollow." + member.getType().getClassName();
               GenericRootClass gc = (GenericRootClass) factory.create(member.getType().getClassName());
               Class subHollowClass = factory.getLoader().loadSpecial(builder, name, gc);
               builder.populateStatics(subHollowClass, factory);
               
               java.lang.reflect.Field field = hollowClass.getField(member.getName() + "Class");
               field.set(null, subHollowClass);
            }
            else
            {
               java.lang.reflect.Field field = hollowClass.getField(member.getName());
               field.set(null, l);
            }
         }
      }
      catch (Exception x)
      {
         throw new RuntimeException("Error while populating statics",x);
      }
   }
   
   private void generateFields(RootClass k, ConstantPoolGen cp, ClassGen cg)
   {
      RootMember[] members = k.getMembers();
      for (int i = 0; i < members.length; i++)
      {
         BasicMember member = (BasicMember) members[i];
         Object l = lMap.get(member);
         if (l == SUBOBJECT)
         {
            Type type = new ObjectType("java.lang.Class");
            FieldGen fg = new FieldGen(ACC_PUBLIC | ACC_STATIC, type, member.getName() + "Class", cp);
            cg.addField(fg.getField());
            
            type = member.getJavaType();
            fg = new FieldGen(ACC_PRIVATE, type, member.getName(), cp);
            cg.addField(fg.getField());
         }
         else if (l != null)
         {
            TLeaf leaf = (TLeaf) l;
            Type type = new ObjectType(leaf.getClass().getName());
            FieldGen fg = new FieldGen(ACC_PUBLIC | ACC_STATIC, type, member.getName(), cp);
            cg.addField(fg.getField());
         }
      }
   }
   
   private void generateMethods(RootClass k, ConstantPoolGen cp, InstructionList il, InstructionFactory factory, ClassGen cg, String className)
   {
      RootMember[] members = k.getMembers();
      for (int i = 0; i < members.length; i++)
      {
         BasicMember member = (BasicMember) members[i];
         Type type = member.getJavaType();
         Object l = lMap.get(member);
         if (l == SUBOBJECT)
         {
            MethodGen mg = new MethodGen(ACC_PUBLIC, type, null, null, nameMangler.mangleMember(member.getName()), className, il, cp);
            il.append(InstructionConstants.ALOAD_0);
            il.append(factory.createGetField(className, member.getName(), type));
            il.append(InstructionConstants.DUP);
            
            BranchHandle bh = il.append(new IFNONNULL(null));
            il.append(InstructionConstants.POP);
            il.append(InstructionConstants.ALOAD_0);
            il.append(factory.createGetStatic(className, member.getName() + "Class", new ObjectType("java.lang.Class")));
            il.append(factory.createInvoke("java.lang.Class", "newInstance", new ObjectType("java.lang.Object"), Type.NO_ARGS, INVOKEVIRTUAL));
            il.append(InstructionConstants.DUP);
            il.append(factory.createCast(new ObjectType("java,lang.Object"), new ObjectType("hep.io.root.core.Hollow")));
            il.append(InstructionConstants.ALOAD_0);
            il.append(factory.createGetField("hep.io.root.core.Hollow", "index", Type.LONG));
            il.append(factory.createInvoke("hep.io.root.core.Hollow", "setHollowIndex", Type.VOID, new Type[]
            {
               Type.LONG
            }, INVOKEVIRTUAL));
            il.append(factory.createCast(new ObjectType("java,lang.Object"), type));
            il.append(InstructionConstants.DUP_X1);
            il.append(factory.createPutField(className, member.getName(), type));
            bh.setTarget(il.append(InstructionFactory.createReturn(type)));
            mg.setMaxStack();
            mg.setMaxLocals();
            cg.addMethod(mg.getMethod());
            il.dispose();
         }
         else if (l == null)
         {
            MethodGen mg = new MethodGen(ACC_PUBLIC, type, null, null, nameMangler.mangleMember(member.getName()), className, il, cp);
            il.append(InstructionFactory.createNull(type));
            il.append(InstructionFactory.createReturn(type));
            mg.setMaxStack();
            mg.setMaxLocals();
            cg.addMethod(mg.getMethod());
            il.dispose();
         }
         else
         {
            TLeaf leaf = (TLeaf) l;
            String leafClassName = leaf.getClass().getName();
            MethodGen mg = new MethodGen(ACC_PUBLIC, type, null, null, nameMangler.mangleMember(member.getName()), className, il, cp);
            
            InstructionHandle try_start = il.append(factory.createGetStatic(className, member.getName(), new ObjectType(leafClassName)));
            il.append(InstructionConstants.ALOAD_0);
            il.append(factory.createGetField("hep.io.root.core.Hollow", "index", Type.LONG));
            
            Type sType = hasSubIndex ? new ArrayType(type, (short) 1) : type;
            Type rType = (sType instanceof BasicType) ? sType : Type.OBJECT;
            leaf.generateReadCode(il, factory, cp, className);
            if (rType != sType)
               il.append(factory.createCast(rType, sType));
            if (hasSubIndex)
            {
               il.append(InstructionConstants.ALOAD_0);
               il.append(factory.createGetField("hep.io.root.core.Hollow", "subIndex", Type.INT));
               il.append(InstructionFactory.createArrayLoad(type));
            }
            
            InstructionHandle try_end = il.append(InstructionFactory.createReturn(type));
            InstructionHandle handler = il.append((Instruction) factory.createNew(new ObjectType("java.lang.RuntimeException")));
            il.append(InstructionConstants.DUP);
            il.append(new PUSH(cp, "IOError while accessing value"));
            il.append(factory.createInvoke("java.lang.RuntimeException", "<init>", Type.VOID, new Type[]
            {
               Type.STRING
            }, INVOKESPECIAL));
            if (System.getProperty("java.version").compareTo("1.4") >= 0)
            {
               il.append(InstructionConstants.DUP_X1);
               il.append(InstructionConstants.SWAP);
               
               Type throwableType = new ObjectType("java.lang.Throwable");
               il.append(factory.createInvoke("java.lang.Throwable", "initCause", throwableType, new Type[]
               {
                  throwableType
               }, INVOKEVIRTUAL));
            }
            il.append(InstructionConstants.ATHROW);
            mg.addExceptionHandler(try_start, try_end, handler, new ObjectType("java.io.IOException"));
            
            mg.setMaxStack();
            mg.setMaxLocals();
            cg.addMethod(mg.getMethod());
            il.dispose();
         }
      }
   }
   
   private void iterativelyAdd(List list, RootClass[] superClasses)
   {
      for (int i = 0; i < superClasses.length; i++)
      {
         RootClass[] supsup = superClasses[i].getSuperClasses();
         iterativelyAdd(list, supsup);
         list.add(superClasses[i]);
      }
   }
}
