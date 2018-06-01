import { configure } from '@storybook/react';
const req = require.context('../lib/es6', true, /.*_stories\.js$/)
import '../node_modules/react-vis/dist/style.css';
configure(() => {
  req.keys().forEach(module => {
    req(module).default();
  })
}, module)
