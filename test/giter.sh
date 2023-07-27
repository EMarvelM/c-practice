#!/bin/bash

echo "Git Add, Commit, and Push Script"
echo "---------------------------------"

# Ask for the commit message
read -p "Enter your commit message: " commit_message

# Add all files to staging area
git add .

# Commit with the provided commit message
git commit -m "$commit_message"

# Push changes to the remote repository
git push

echo "Git push completed successfully."
