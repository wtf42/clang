// RUN: %clang_cc1 %s -emit-llvm -o %t

int main() {
  int foo = 42, bar = 4, baz;
  asm __ir ("  %foobar = alloca i32, align 4                  \n"
            "  store i32 %0, i32* %foobar, align 4            \n"
            "  %3 = load i32, i32* %foobar, align 4           \n"
            "  %4 = xor i32 %3, %1                            \n"
            "  %5 = insertvalue { i32, i32 } undef, i32 %4, 0 \n"
            "  %6 = insertvalue { i32, i32 } %5, i32 %2, 1    \n"
            "  ret { i32, i32 } %6                            \n"
            : "=r"(bar), "=r"(baz)
            : "r"(foo), "r"(42), "r"(bar / 2));
  foo += bar * baz;
  return foo;
}
