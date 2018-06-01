import { configure } from '@storybook/react';
const req = require.context('../lib/es6', true, /.*_stories\.js$/)
configure(() => {
  req.keys().forEach(module => {
    req(module).default();
  })
}, module)
