#!/bin/bash
source ../../../project.sh

IMPALA_FILE=$1
THORIN_LOG=${1%.*}.thorin.log
THORIN_OPT_LOG=${1%.*}_opt.thorin.log
LLVM_FILE=${1%.*}
LLVM_FILE_ENDING=${1%.*}.ll
LLVM_LOG=${1%.*}.ll.log
BC_FILE=${1%.*}.bc
OUT_FILE=${1%.*}.out

# echo "Start compiling to thorin"
# impala --emit-thorin $IMPALA_FILE > $THORIN_LOG
# echo "Start compiling to thorin with optimization"
# impala --emit-thorin -Othorin $IMPALA_FILE > $THORIN_OPT_LOG
echo "Start compiling to llvm with optimization"
impala --emit-llvm -O3 -Othorin $IMPALA_FILE -o $LLVM_FILE > $LLVM_LOG

echo "Linking"
# clang -g -O0 ../lib.c newton_lib.c libbmp.c -c
clang -g -O0 -flto lib.o newton_lib.o libbmp.o $LLVM_FILE_ENDING -s -o $OUT_FILE