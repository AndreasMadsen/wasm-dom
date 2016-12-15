'use strict';

const fs = require('fs');
const path = require('path');

const structures = {
  'dictionary': require('./structures/dictionary.js'),
  'enum': require('./structures/enum.js')
};

const webIDL = JSON.parse(
  fs.readFileSync(
    path.resolve(__dirname, '..', 'webidl', 'dom.json'),
    'utf8'
  )
);

const headerFile = fs.openSync(
  path.resolve(__dirname, '..', 'build', 'dom.hpp'),
  'w'
);

fs.writeSync(headerFile, `\
#pragma once
#include <string>
#include <vector>

namespace dom {
\n`);

for (const fragment of webIDL) {
  if (structures.hasOwnProperty(fragment.type)) {
    const Structure = structures[fragment.type];
    const structure = new Structure(fragment);

    fs.writeSync(headerFile, structure.header() + '\n');
  }
}

fs.writeSync(headerFile, '} // namespace dom\n');
fs.closeSync(headerFile);
