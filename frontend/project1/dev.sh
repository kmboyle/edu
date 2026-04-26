#!/bin/bash
# Development environment script for project1
echo "Entering development environment for project1..."
nix-shell -p nodejs --run "$*"
