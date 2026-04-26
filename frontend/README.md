# Frontend Projects with Angular and pnpm

This directory contains multiple Angular projects managed with pnpm.

## Project Structure

- project1/ - First Angular application
- project2/ - Second Angular application  
- project3/ - Third Angular application

## Setup Instructions

### Prerequisites

1. Install Node.js and npm
2. Install pnpm globally: `npm install -g pnpm`

### Creating New Angular Projects

To create a new Angular project using npx (recommended approach on NixOS):

```bash
# Navigate to desired project directory
cd project1

# Create new Angular app using npx (no global installation needed)
npx -p @angular/cli ng new . --skip-tests --skip-git --package-manager=pnpm --style=scss --routing=true
```

### Alternative: Using Global Angular CLI

If you prefer to install Angular CLI globally (not recommended on NixOS):

```bash
# Install Angular CLI globally
npm install -g @angular/cli

# Create new Angular app
ng new project-name --skip-tests --skip-git --package-manager=pnpm --style=scss --routing=true
```

### Managing Dependencies

Use pnpm commands in the project directory:

- `pnpm install` - Install all dependencies
- `pnpm add <package>` - Add a dependency
- `pnpm remove <package>` - Remove a dependency
- `pnpm add -D <package>` - Add a dev dependency

### Running Projects

- `ng serve` - Serve project (from within project directory)
- `ng build` - Build project
- `ng test` - Run tests

## NixOS Specific Notes

On NixOS, it's recommended to use `npx` for Angular CLI commands to avoid global installation issues. You can also use the `nodePackages` set in your NixOS configuration to install global packages if needed.

```bash
# Example of using npx for Angular CLI commands
npx -p @angular/cli ng new my-app --skip-tests --skip-git --package-manager=pnpm
```
