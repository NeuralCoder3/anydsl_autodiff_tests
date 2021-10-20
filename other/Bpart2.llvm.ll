; ModuleID = 'test/Bpart2.llvm'
source_filename = "test/Bpart2.llvm"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@"%_3392" = global [3 x i32] [i32 12, i32 13, i32 14]
@"%_3346" = global [3 x i32] [i32 42, i32 43, i32 44]

define i32 @main() {
main_start:
  br label %main

main:                                             ; preds = %main_start
  br label %while_head

while_head:                                       ; preds = %while_body, %main
  %0 = phi i32 [ %4, %while_body ], [ 0, %main ]
  %1 = phi i32 [ %10, %while_body ], [ 0, %main ]
  %2 = icmp slt i32 %0, 3
  br i1 %2, label %while_body, label %break

while_body:                                       ; preds = %while_head
  %3 = zext i32 %0 to i64
  %4 = add nsw i32 1, %0
  %5 = getelementptr inbounds [0 x i32], [0 x i32]* bitcast ([3 x i32]* @"%_3392" to [0 x i32]*), i64 0, i64 %3
  %6 = getelementptr inbounds [0 x i32], [0 x i32]* bitcast ([3 x i32]* @"%_3346" to [0 x i32]*), i64 0, i64 %3
  %7 = load i32, i32* %6, align 4
  %8 = load i32, i32* %5, align 4
  %9 = mul nsw i32 %7, %8
  %10 = add nsw i32 %1, %9
  br label %while_head

break:                                            ; preds = %while_head
  %11 = add nsw i32 42, %1
  br label %return

return:                                           ; preds = %break
  %12 = phi i32 [ %11, %break ]
  ret i32 %12
}
