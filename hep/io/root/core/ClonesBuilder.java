package hep.io.root.core;

import hep.io.root.*;

import org.apache.bcel.*;
import org.apache.bcel.classfile.*;
import org.apache.bcel.generic.*;

import java.util.*;


/**
 * Creates a class which extends Clones and which represents a set of clones
 * read in split mode. Note when optimization is enabled in the Root file,
 * multiple logical fields may be read into a single field. Suitable offsets
 * are automatically built into the corresponding Clone for accessing data
 * from these fields.
 * @see hep.io.root.core.Clones
 * @author tonyj
 * @version $Id: ClonesBuilder.java,v 1.3 2005/08/10 00:56:30 tonyj Exp $
 */
class ClonesBuilder implements ClassBuilder, Constants
{
   private static NameMangler nameMangler = NameMangler.instance();
   private boolean optimize;

   public String getStem()
   {
      return "hep.io.root.clones";
   }

   public JavaClass build(GenericRootClass klass)
   {
      optimize = (klass.getStreamerInfo().getBits() & (1 << 12)) == 0;
      //System.out.println("bits=" + Integer.toHexString(klass.getStreamerInfo().getBits()) + " optimize=" + optimize);

      String className = getStem() + "." + klass.getClassName();
      ClassGen cg = new ClassGen(className, "hep/io/root/core/Clones", "<generated>", ACC_PUBLIC | ACC_SUPER, null);
      ConstantPoolGen cp = cg.getConstantPool();
      InstructionList il = new InstructionList();
      InstructionFactory factory = new InstructionFactory(cg);

      cg.addEmptyConstructor(ACC_PUBLIC);

      // Build the complete list of superclasses
      List sup = new ArrayList();
      RootClass[] superClasses = klass.getSuperClasses();
      iterativelyAdd(sup, superClasses);
      sup.add(klass);

      // Generate the fields
      for (Iterator i = sup.iterator(); i.hasNext();)
         generateFields((RootClass) i.next(), cp, cg);

      // Generate the streamer method
      MethodGen mg = new MethodGen(ACC_PUBLIC, Type.VOID, new Type[]
         {
            new ObjectType("hep/io/root/core/RootInput"), Type.INT
         }, new String[] { "in", "nClones" }, "read", className, il, cp);
      mg.addException("java/io/IOException");

      for (Iterator i = sup.iterator(); i.hasNext();)
         generateStreamer((RootClass) i.next(), cp, il, factory, className);

      il.append(new RETURN());
      mg.setMaxStack();
      mg.setMaxLocals();
      cg.addMethod(mg.getMethod());
      il.dispose();

      return cg.getJavaClass();
   }

   private void generateFields(RootClass k, ConstantPoolGen cp, ClassGen cg)
   {
      if (k.getClassName().equals("TObject") && optimize)
         return;

      RootMember[] members = k.getMembers();
      for (int i = 0; i < members.length; i++)
      {
         BasicMember member = (BasicMember) members[i];
         if (optimize && ((i + 1) < members.length) && (member.getArrayDim() == 0) && member.getJavaType().equals(((BasicMember) members[i + 1]).getJavaType())) {}
         else
         {
            Type type = ((BasicMember) members[i]).getJavaType();
            type = new ArrayType(type, 1);

            FieldGen fg = new FieldGen(ACC_PUBLIC, type, members[i].getName(), cp);
            cg.addField(fg.getField());
         }
      }
   }

   private void generateStreamer(RootClass k, ConstantPoolGen cp, InstructionList il, InstructionFactory factory, String className)
   {
      if (k.getClassName().equals("TObject") && optimize)
         return;

      RootMember[] members = k.getMembers();
      int multiplier = 1;
      for (int i = 0; i < members.length; i++)
      {
         BasicMember member = (BasicMember) members[i];
         if (optimize && ((i + 1) < members.length) && (member.getArrayDim() == 0) && member.getJavaType().equals(((BasicMember) members[i + 1]).getJavaType()))
         {
            multiplier++;
         }
         else
         {
            Type type = member.getJavaType();
            Type arrayType = new ArrayType(type, 1);
            il.append(InstructionConstants.ALOAD_0);
            il.append(InstructionConstants.ALOAD_1);
            il.append(InstructionConstants.ILOAD_2); //length
            if (multiplier > 1)
            {
               il.append(new PUSH(cp, multiplier));
               il.append(InstructionConstants.IMUL);
            }
            String varCounter = member.getVarCounter();
            if (varCounter == null)
            {
               for (int j = 0; j < member.getArrayDim(); j++)
                  il.append(new PUSH(cp, member.getMaxIndex(j)));

               il.append((Instruction) factory.createNewArray(((BasicRootClass) member.getType()).getJavaType(), (short) (member.getArrayDim() + 1)));
               il.append(InstructionConstants.DUP_X1);
               if (member.getArrayDim() == 0)
               {
                  if (type instanceof ObjectType)
                  {
                     il.append(new PUSH(cp,member.getType().getClassName()));
                     il.append(factory.createInvoke("hep.io.root.core.IOUtils", "readFixedArray", Type.VOID, new Type[]
                           {
                              RootType.ROOTINPUT, new ArrayType(Type.OBJECT, 1), RootType.STRING
                           }, INVOKESTATIC));                  
                  }
                  else
                  {
                     il.append(factory.createInvoke("hep.io.root.core.RootInput", "readFixedArray", Type.VOID, new Type[]
                           {
                              arrayType
                           }, INVOKEINTERFACE));
                  }
               }
               else
               {
                  il.append(factory.createInvoke("hep.io.root.core.RootInput", "readMultiArray", Type.VOID, new Type[]
                        {
                           new ArrayType(Type.OBJECT, 1)
                        }, INVOKEINTERFACE));
               }
            }
            else
            {
               il.append((Instruction) factory.createNewArray(type, (short)1));
               il.append(InstructionConstants.DUP_X1);
               il.append(InstructionConstants.ALOAD_0);
               il.append(factory.createFieldAccess(className, varCounter, RootType.INTARRAY, Constants.GETFIELD));
               il.append(factory.createInvoke("hep.io.root.core.IOUtils", "readVariableMultiArray", Type.VOID, new Type[]
                        {
                           RootType.ROOTINPUT,arrayType,RootType.INTARRAY
                        }, INVOKESTATIC));
            }
            il.append(factory.createPutField(className, member.getName(), arrayType));
            multiplier = 1;
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
