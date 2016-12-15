# WebAssembly DOM

> HTML5/DOM interface for C++ and WebAssembly

**work in progress** (well it is unlikely I will finish it).

## Idea

By having the entire DOM Interface wrapped in C++ one could write a full webpage in only C++. This will would also make static analysis very easy, as that comes for free with `clang` and `gcc`.

## How

The HTML, DOM, and CSSOM specifications have all the interfaces specified in [WebIDL](https://heycam.github.io/webidl/).
This can be scraped from the specification pages [[1](https://dom.spec.whatwg.org/), [2](https://html.spec.whatwg.org/), [3](https://drafts.csswg.org/cssom/)] using [`webidl-extract`](https://github.com/AndreasMadsen/webidl-extract). W3C has a parser for this format called [`webidl2`](https://github.com/w3c/webidl2.js) which can be used to turn it into a `JSON` format, see [`./webidl`](https://github.com/AndreasMadsen/wasm-dom/tree/master/webidl). From this `JSON` structure one could automatically generate C++ ([header](https://github.com/AndreasMadsen/wasm-dom/blob/master/build/dom.hpp) and code) which wraps [`emscripten::val`]( http://kripken.github.io/emscripten-site/docs/api_reference/val.h.html).
