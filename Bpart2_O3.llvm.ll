; ModuleID = 'test/Bpart2_O3.llvm'
source_filename = "test/Bpart2_O3.llvm"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@"%_3392" = local_unnamed_addr global [3 x i32] [i32 12, i32 13, i32 14]
@"%_3346" = local_unnamed_addr global [3 x i32] [i32 42, i32 43, i32 44]

; Function Attrs: norecurse nounwind readonly
define i32 @main() local_unnamed_addr #0 {
main_start:
  %0 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3346", i64 0, i64 0), align 4
  %1 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3392", i64 0, i64 0), align 4
  %2 = mul nsw i32 %1, %0
  %3 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3346", i64 0, i64 1), align 4
  %4 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3392", i64 0, i64 1), align 4
  %5 = mul nsw i32 %4, %3
  %6 = add nsw i32 %5, %2
  %7 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3346", i64 0, i64 2), align 4
  %8 = load i32, i32* getelementptr inbounds ([3 x i32], [3 x i32]* @"%_3392", i64 0, i64 2), align 4
  %9 = mul nsw i32 %8, %7
  %10 = add nsw i32 %9, %6
  %11 = add nsw i32 %10, 42
  ret i32 %11
}

attributes #0 = { norecurse nounwind readonly }
