#!/bin/bash
source ../../project.sh

IMPALA_FILE=$1
THORIN_LOG=${1%.*}.thorin.log
THORIN_OPT_LOG=${1%.*}_opt.thorin.log
LLVM_FILE=${1%.*}
LLVM_FILE_ENDING=${1%.*}.ll
LLVM_LOG=${1%.*}.ll.log
BC_FILE=${1%.*}.bc
OUT_FILE=${1%.*}.out

echo "Start compiling to thorin"
impala --emit-thorin $IMPALA_FILE > $THORIN_LOG
echo "Start compiling to thorin with optimization"
impala --emit-thorin -Othorin $IMPALA_FILE > $THORIN_OPT_LOG
echo "Start compiling to llvm with optimization"
impala --emit-llvm -O3 -Othorin $IMPALA_FILE -o $LLVM_FILE > $LLVM_LOG

# echo "Assembling LLVM"
# llvm-as -o $BC_FILE $LLVM_FILE_ENDING
echo "Linking"
# clang -L../../runtime/build/lib -lruntime -lm lib.c $BC_FILE -o $OUT_FILE
# clang -L. -lruntime -lgbeinterp -lm lib.c $BC_FILE -o $OUT_FILE
# clang -L../../runtime/build/lib -lruntime -L/usr/lib/beignet -lgbeinterp -lm lib.c $BC_FILE -o $OUT_FILE
clang -O3 lib.c -c
# clang -O3 -flto lib.o $LLVM_FILE_ENDING -lm -lpcre -lgmp -s -o $OUT_FILE
clang -O3 -flto lib.o $LLVM_FILE_ENDING -s -o $OUT_FILE