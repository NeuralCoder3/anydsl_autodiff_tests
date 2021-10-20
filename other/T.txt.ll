; ModuleID = 'test/T.txt'
source_filename = "test/T.txt"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main() {
main_start:
  br label %main

main:                                             ; preds = %main_start
  br label %return

return:                                           ; preds = %main
  %0 = phi i32 [ 47, %main ]
  ret i32 %0
}
