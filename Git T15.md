
Start by **creating a new folder**, which will contain the repo on your laptop (call it `RISC-V-T15` for simplicity).

Then, go to the folder, and **initialize a new git**, using `git init`.

Now that you have a git initialized, you simply need to connect yourself to the repo, write:

```bash
git remote add origin https://github.com/Benji-clm/RISC-V-T15.git
```

Once, the origin has been created, you want to **pull the repo** (very important to do it now, else it might cause a lot of merging issues later on).

```bash
git pull
```

This might prompt you to open GitHub to allow VSCode to connect.
Great you've got the repo.

To add individual files use:
```bash
git add [path to file]
```

If you want to check what files you've added on the stage use `git satus`

Then to commit:

```bash
git commit -m "reason for commit"
```

Keep the reason for commit relatively short, and one commit per file, to allow us to properly track the changes..

You then want to push the commits on the GitHub, the first time you'll need to set the remote as **upstream**:

```bash
git push --set-upstream origin master
```

Make user to use `master` as the branch, as this is the branch our GitHub is using, if you are in the wrong branch (i.e. `main`), use:

```bash
git checkout master
```

You're all set! Now you just need to use `git push` every time you want to push your commits onto the GitHub.

> **DO NOT FORGET** `git pull` before trying to add and commit files/changes, else it might cause bugs.

