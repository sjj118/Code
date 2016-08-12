git add -A
git status
set description=%1
if defined description (
git commit -m "%1"
) else (
git commit -m "%date:~0,-2%%time%"
)
git push
