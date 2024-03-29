package hep.io.root.core;


/*
 * InterfaceBuilder.java
 *
 * Created on December 17, 2001, 5:11 PM
 */
import hep.io.root.*;

import org.apache.bcel.*;
import org.apache.bcel.classfile.*;
import org.apache.bcel.generic.*;

import java.util.*;


/**
 * Builds a class which extends Clone and represents one item in a TClonesArray.
 * This is used when the TClonesArray is read in split mode.
 * Each class contains its index within the TClonesArray, and a pointer to the
 * corresponding class which extends Clones.
 * Clone2Builder is used for Root 3.01 and later.
 * @see hep.io.root.core.Clones2Builder
 * @author tonyj
 * @version $Id: Clone2Builder.java,v 1.3 2004/06/28 15:21:22 tonyj Exp $
 */
class Clone2Builder implements ClassBuilder, Constants
{
   private static NameMangler nameMangler = NameMangler.instance();
   private static boolean optimize;

   public String getStem()
   {
      return "hep.io.root.clone2";
   }

   public JavaClass build(GenericRootClass klass)
   {
      optimize = (klass.getStreamerInfo().getBits() & (1 << 12)) == 0;

      String className = getStem() + "." + klass.getClassName();
      String clonesClassName = "hep.io.root.clones2." + klass.getClassName();
      ClassGen cg = new ClassGen(className, "hep/io/root/core/Clone2", "<generated>", ACC_PUBLIC | ACC_SUPER, new String[]
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

      // Create the fields
      cg.addField(new FieldGen(ACC_PRIVATE, Type.INT, "index", cp).getField());
      cg.addField(new FieldGen(ACC_PRIVATE, new ObjectType(clonesClassName), "clones", cp).getField());

      //Generate the setData method
      MethodGen mg = new MethodGen(ACC_PUBLIC, Type.VOID, new Type[]
         {
            Type.INT, new ObjectType("hep.io.root.core.Clones2")
         }, new String[] { "index", "clones" }, "setData", className, il, cp);
      il.append(InstructionConstants.ALOAD_0);
      il.append(InstructionConstants.ILOAD_1);
      il.append(factory.createPutField(className, "index", Type.INT));
      il.append(InstructionConstants.ALOAD_0);
      il.append(InstructionConstants.ALOAD_2);
      il.append(factory.createCast(new ObjectType("hep.io.root.core.Clones2"), new ObjectType(clonesClassName)));
      il.append(factory.createPutField(className, "clones", new ObjectType(clonesClassName)));
      il.append(InstructionConstants.RETURN);
      mg.setMaxStack();
      mg.setMaxLocals();
      cg.addMethod(mg.getMethod());
      il.dispose();

      // Generate the accessor methods
      for (Iterator i = sup.iterator(); i.hasNext();)
         generateMethods((RootClass) i.next(), cp, il, factory, cg, className, clonesClassName);

      return cg.getJavaClass();
   }

   private static void generateMethods(RootClass k, ConstantPoolGen cp, InstructionList il, InstructionFactory factory, ClassGen cg, String className, String clonesClassName)
   {
      RootMember[] members = k.getMembers();

      for (int i = 0; i < members.length; i++)
      {
         BasicMember member = (BasicMember) members[i];

         Type type = member.getJavaType();
         Type arrayType = new ArrayType(type, 1);
         MethodGen mg = new MethodGen(ACC_PUBLIC, type, null, null, nameMangler.mangleMember(member.getName()), className, il, cp);
         il.append(InstructionConstants.ALOAD_0);
         il.append(factory.createGetField(className, "clones", new ObjectType(clonesClassName)));
         il.append(InstructionConstants.ALOAD_0);
         il.append(factory.createGetField(className, "index", Type.INT));

         il.append(factory.createInvoke(clonesClassName, nameMangler.mangleMember(member.getName()), type, new Type[]
               {
                  Type.INT
               }, INVOKEVIRTUAL));

         il.append(InstructionFactory.createReturn(type));
         mg.setMaxStack();
         mg.setMaxLocals();
         cg.addMethod(mg.getMethod());
         il.dispose();
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
