To recreate libjvm.dll.a on cygwin using g++:

dlltool --input-def jvm.def --kill-at --dllname jvm.dll --output-lib libjvm.dll.a
