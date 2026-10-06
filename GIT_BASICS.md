# Git Basics: Command Line Cheat Sheet

A practical guide to using Git from the terminal, written for the `Learning_OOP` repo.

---

## 1. Core Concepts

| Term | Meaning |
|------|---------|
| **Repository (repo)** | A project folder tracked by Git (has a hidden `.git` folder inside). |
| **Working directory** | The files you see and edit on your computer. |
| **Staging area** | A "waiting room" where you choose which changes go into the next commit. |
| **Commit** | A saved snapshot of your staged changes, with a message. |
| **Branch** | A separate line of development. The default one is `main`. |
| **Remote** | A copy of the repo hosted online (GitHub). Usually called `origin`. |

The basic flow:

```
edit files  ->  git add  ->  git commit  ->  git push
(working dir)   (staging)     (local repo)     (GitHub)
```

---

## 2. One-Time Setup

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
git config --global init.defaultBranch main
git config --global pull.rebase false     # makes `git pull` merge by default

git config --list                         # view your settings
```

---

## 3. Starting a Repository

**Start a new repo from a folder:**

```bash
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/USERNAME/REPO.git
git push -u origin main
```

**Copy an existing repo from GitHub:**

```bash
git clone https://github.com/USERNAME/REPO.git
```

> Tip: When creating a repo on GitHub that you'll push an existing project to,
> leave "Add a README" **unchecked**. Otherwise the remote and local histories
> differ and your first push gets rejected.

---

## 4. Everyday Workflow

```bash
git status                    # what changed? what's staged?
git add file.py               # stage one file
git add .                     # stage everything in the current folder
git commit -m "Add Dog class" # save a snapshot
git push                      # upload commits to GitHub
git pull                      # download and merge changes from GitHub
```

**Good commit messages** are short and say what changed:
`Add Student class with constructor` is better than `update` or `stuff`.

---

## 5. Viewing History and Changes

```bash
git log                       # full history
git log --oneline             # compact history
git log --oneline --graph     # history with branch graph
git diff                      # unstaged changes
git diff --staged             # staged changes
git show <commit-id>          # details of one commit
```

---

## 6. Undoing Things

| Situation | Command |
|-----------|---------|
| Unstage a file (keep your edits) | `git restore --staged file.py` |
| Discard edits to a file (**cannot be undone**) | `git restore file.py` |
| Fix the last commit message | `git commit --amend -m "new message"` |
| Undo last commit, keep changes staged | `git reset --soft HEAD~1` |
| Undo last commit, keep changes unstaged | `git reset HEAD~1` |
| Undo a pushed commit safely | `git revert <commit-id>` |

> Avoid `git reset --hard` unless you are sure. It permanently deletes uncommitted work.

---

## 7. Branches

```bash
git branch                    # list branches
git branch feature-login      # create a branch
git switch feature-login      # move to it
git switch -c feature-login   # create and move in one step
git switch main               # go back to main

git merge feature-login       # merge it into the branch you're on
git branch -d feature-login   # delete the branch after merging

git push -u origin feature-login   # push a new branch to GitHub
```

Typical flow: create a branch, make commits on it, switch to `main`, merge, push.

---

## 8. Working with Remotes

```bash
git remote -v                                  # show remotes
git remote add origin <url>                    # add a remote
git remote set-url origin <new-url>            # change remote URL
git fetch                                      # download changes without merging
git pull                                       # fetch + merge
git push                                       # upload your commits
```

---

## 9. Merge Conflicts

A conflict happens when two versions change the same lines. Git marks the file:

```
<<<<<<< HEAD
your version
=======
their version
>>>>>>> branch-name
```

To resolve:

1. Open the file and edit it to the final content you want.
2. Delete the `<<<<<<<`, `=======`, and `>>>>>>>` lines.
3. Then run:

```bash
git add file.py
git commit -m "Resolve merge conflict"
```

---

## 10. Using .gitignore

A `.gitignore` file lists files Git should **not** track: compiled files,
virtual environments, editor settings, secrets, and OS junk.

Common patterns:

```
*.log          # all .log files
build/         # an entire folder
!keep.log      # exception: track this one
```

If a file is already tracked and you add it to `.gitignore` later, stop tracking it with:

```bash
git rm --cached file.txt         # a single file
git rm -r --cached folder/       # a folder
git commit -m "Stop tracking file.txt"
```

Never commit passwords, API keys, or `.env` files.

---

## 11. Saving Work Temporarily (Stash)

```bash
git stash                     # shelve uncommitted changes
git stash list                # see stashes
git stash pop                 # bring the latest stash back
```

---

## 12. Authentication Notes

GitHub does not accept your account password over HTTPS. Use either:

- A **Personal Access Token** as the password, or
- The **GitHub CLI**: `gh auth login`, or
- **SSH keys** (`ssh-keygen -t ed25519`, then add the public key to GitHub).

On macOS, the credential helper stores your login so you only enter it once.

---

## 13. Quick Troubleshooting

| Error | Fix |
|-------|-----|
| `rejected ... (fetch first)` | Run `git pull`, then `git push`. |
| `divergent branches` | Run `git config --global pull.rebase false`, then pull again. |
| `refusing to merge unrelated histories` | `git pull origin main --allow-unrelated-histories` |
| `not a git repository` | You're in the wrong folder, or need `git init`. |
| Stuck in vim after a merge | Press `Esc`, type `:wq`, press Enter. |
| Stuck in nano | `Ctrl+X`, then `Y`, then Enter. |
| `nothing to commit` | You haven't changed or staged anything. Check `git status`. |

---

## 14. Daily Cheat Sheet

```bash
git pull                      # start the day: get the latest
# ...edit code...
git status                    # review
git add .
git commit -m "Clear message"
git push                      # end the day: upload
```
