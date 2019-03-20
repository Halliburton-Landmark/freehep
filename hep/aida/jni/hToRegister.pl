
open (H, "<$ARGV[0].h") || die "Cannot open $ARGV[0].h";
open (R, ">$ARGV[0].r") || die "Cannot open $ARGV[0].r";

$methods = 0;
print R "\n";
print R "    JNINativeMethod methods$ARGV[0]"; print R "[] = {\n";
print R "        { (char*)\"finalize\", (char*)\"(J)V\", (void*)Java_hep_aida_jni_CProxy_finalize },\n";
print R "\n";
        
while ($line = <H>) {
    chomp($line);
    if ($line =~ /Method:\s+(.+)/) {
        print R "        { (char*)\"$1\", ";
    }
    if ($line =~ /Signature:\s+(.+)/) {
        print R "(char*)\"$1\", ";
    }
    if ($line =~ /JNICALL\s+(.+)/) {
        print R "(void*)$1 },\n";
        $methods++;
    }
}
print R "    };\n";
print R "1+$methods\n";

close H;
close R;
