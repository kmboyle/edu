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

### Creating Angular Projects
1. Navigate to project directory: `cd project1`
2. Create Angular app: `ng new . --skip-tests --skip-git --package-manager=pnpm`
3. Repeat for other projects

### Managing Dependencies
Use pnpm commands in the root:
- `pnpm install` - Install all dependencies
- `pnpm add <package>` - Add a dependency
- `pnpm remove <package>` - Remove a dependency

### Running Projects
- `ng serve` - Serve project (from within project directory)
