'use strict';

class Structure {
  constructor(name, structure, include) {
    this.name = name;
    this._structure = structure;
    this._include = include;

    this._include.addDependency({name: '../_basic', format: false});
  }

  header() {
    return '#pragma once\n' +
            this._include.header() + '\n' +
           'namespace dom {\n' +
           '\n' + 
           this._structure.header() + '\n' +
           '} // namespace dom\n';
  }

  body() {
    return this._include.body() + '\n' + this._structure.body();
  }
}

module.exports = Structure;
