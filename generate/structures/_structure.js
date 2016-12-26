'use strict';

class Structure {
  constructor(name, structure, include) {
    this.name = name;
    this._structure = structure;
    this._include = include;

    this._include.addDependency({name: '../_basic', format: false});
  }

  header() {
    const headerName = this.name.toUpperCase();

    return `#ifndef WASM_DOM_${headerName}_H_\n` +
           `#define WASM_DOM_${headerName}_H_\n` +
           '\n' +
            this._include.header() + '\n' +
           'namespace dom {\n' +
           '\n' +
           this._structure.header() + '\n' +
           '} // namespace dom\n' +
           `#endif // WASM_DOM_${headerName}_H_\n`;
  }

  body() {
    return this._include.body() + '\n' + this._structure.body();
  }
}

module.exports = Structure;
