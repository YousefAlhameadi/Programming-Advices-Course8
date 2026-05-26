@echo off
echo Syncing with GitHub...
git pull origin main
echo Uploading new code...
git add .
git commit -m "Added a new problem solution"
git push origin main
echo Successfully uploaded!
pause