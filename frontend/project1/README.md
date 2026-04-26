# Project 1 - Angular Application

This is a basic Angular application created for NixOS environment.

## Development

To develop this application on NixOS, you have several options:

### Option 1: Using nix-shell (Recommended)
```bash
# Enter the development environment
nix-shell

# Install dependencies
npm install

# Start the development server
ng serve
```

### Option 2: Using direnv (Automated environment)
If you have direnv installed:
1. Create a .envrc file with:
   ```bash
   export PATH=$PWD/node_modules/.bin:$PATH
   ```
2. Run `direnv allow` in the project directory

### Option 3: Global Nix installation
Add to your NixOS configuration:
```nix
environment.systemPackages = with pkgs; [
  nodejs
  nodePackages.typescript
];
```

## Project Structure
- \`src/\` - Source code directory
- \`angular.json\` - Angular CLI configuration
- \`package.json\` - Node.js dependencies
- \`tsconfig.json\` - TypeScript configuration

## Available Scripts
- \`npm start\` - Start development server
- \`npm run build\` - Build for production
- \`npm test\` - Run tests

