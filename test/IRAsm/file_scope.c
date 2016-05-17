// RUN: %clang_cc1 %s -emit-llvm -o %t

asm __ir (
"; Function Attrs: nounwind              \n"
"define i32 @mul(i32 %x) #0 {            \n"
"entry:                                  \n"
"  %x.addr = alloca i32, align 4         \n"
"  store i32 %x, i32* %x.addr, align 4   \n"
"  %0 = load i32, i32* %x.addr, align 4  \n"
"  %mul = mul nsw i32 %0, 2              \n"
"  ret i32 %mul                          \n"
"}                                       \n"
);

int main() {
  return mul(42);
}
