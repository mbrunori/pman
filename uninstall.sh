#!/bin/bash

# Uninstall script for pman

echo "pman will now be uninstalled for user $USER [y/N]"
read -r response
if [[ ! "$response" =~ ^([yY][eE][sS]|[yY])$ ]]; then
    echo "Uninstall cancelled."
    exit 0
fi

echo "Removing binary..."
if [ -f "/usr/local/bin/pman" ]; then
    sudo rm "/usr/local/bin/pman"
fi

echo "Removing configuration and data..."
rm -f "$HOME/.pmanrc"
rm -rf "$HOME/.config/pman"

echo "pman has been successfully uninstalled."
