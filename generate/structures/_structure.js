'use strict';

class Structure {
  constructor(structure) {
    this._structure = structure;
  }

  header() {
    return this._structure.header();
  }

  body() {
    return this._structure.body();
  }
}

module.exports = Structure;
