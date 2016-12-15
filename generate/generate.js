'use strict';

const fs = require('fs');
const path = require('path');

const Include = require('./cpp/include.js');

const structures = {
  'dictionary': require('./structures/dictionary.js'),
  'interface': require('./structures/interface.js'),
  'callback interface': require('./structures/interface.js'),
  'enum': require('./structures/enum.js')
};

const webIDL = JSON.parse(
  fs.readFileSync(
    path.resolve(__dirname, '..', 'webidl', 'dom.json'),
    'utf8'
  )
);

const main = new Include();

for (const fragment of webIDL) {
  if (structures.hasOwnProperty(fragment.type)) {
    const Structure = structures[fragment.type];
    const structure = new Structure(fragment);

    fs.writeFileSync(
      path.resolve(__dirname, '..', 'build', 'dom', structure.name.toLowerCase() + '.hpp'),
      structure.header()
    );

    main.addDependency({
      name: 'dom/' + structure.name.toLowerCase(),
      format: false
    });
  }
}

fs.writeFileSync(
  path.resolve(__dirname, '..', 'build', 'dom.hpp'),
  '#pragma once\n\n' + main.header()
);
