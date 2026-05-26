@echo off
echo Uploading new code to GitHub...
git add .
git commit -m "Added a new problem solution"
git push
echo Successfully uploaded!
pause