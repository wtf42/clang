// RUN: %clang_cc1 %s -emit-llvm -o %t

int main() {
  int foo = 42, bar;
  asm __ir ("  %1 = mul nsw i32 %0, 2  \n"
            "  %2 = sub nsw i32 %1, 1  \n"
            "  ret i32 %2              \n"
            : "=r"(bar)
            : "r"(foo));
  foo ^= bar;
  return foo;
}
