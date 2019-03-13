# My solution to ["The Modern C++ Challenge"][1]

Some notes.
1. I don't bother `constexpr`-specify any function. It's a burden, and not that useful in practice.
1. I don't bother `explicit`-specify any constructor. I like implicit conversion. If bugs are introduced then, it's your fault :/
1. If you see something not nice or inferior to the solution given in the book, please [comment][2]. I think I can explain.
1. For those pedantic, assume `sizeof(int) >= 4` and `CHAR_BIT` is 8.
1. Thanks for watching :]

[1]: http://scottmeyers.blogspot.com/2018/06/interesting-book-modern-c-challenge.html
[2]: https://github.com/Lingxi-Li/Modern_CPP_Challenge_Solution/issues/new
