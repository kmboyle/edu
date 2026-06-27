# Project 1 - Angular Application

This is a basic Angular application created for NixOS environment.

## Development

To develop this application on NixOS, you have several options:

### Option 1: Using nix-shell (Recommended)

```bash
# Enter the development environment
nix-shell

# Install dependencies with pnpm (recommended for this project)
pnpm install

# Start the development server
ng serve

# Or if ng in not installed
npx ng serve
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

## Fixing TypeScript Peer Dependency Issues

If you encounter TypeScript peer dependency conflicts (like ERESOLVE errors), use:

```bash
# Install with pnpm and ignore peer dependencies
pnpm install --strict-peer-dependencies=false

# Or force installation
pnpm install --force
```

## Project Structure

- `src/` - Source code directory
- `angular.json` - Angular CLI configuration
- `package.json` - Node.js dependencies
- `tsconfig.json` - TypeScript configuration

## Available Scripts

- `pnpm start` - Start development server
- `pnpm run build` - Build for production
- `pnpm test` - Run tests
