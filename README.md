# Semester Assignment 1 - COS214

## Git Branching Strategy
- ```master``` this branch contains the production code, this code needs to work at all times. This is what we are handing in.
- ```develop``` this branch contains the code before it is merge into the master branch.
- ```feature-*``` used to develop new features for the project. Branches off from the development branch.

---
<img src="https://nvie.com/img/git-model@2x.png" align="center" width="500px" height="500px"/>

fig. (<a href="https://nvie.com/posts/a-successful-git-branching-model/">Original Article</a>)

---

Follow the instructions below to get a local git repo going and to create a branch(using the above mentioned naming convention).

## 0. Install git
<a target="#" href="https://git-scm.com/book/en/v2/Getting-Started-Installing-Git">Follow this link for a guide(This will open in a new tab)</a>

## 1. Clone the repository

<img align="right" width="300" src="https://firstcontributions.github.io/assets/Readme/clone.png" alt="clone this repository" />

Now clone the forked repository to your machine. Go to your GitHub account, open the forked repository, click on the code button and then click the _copy to clipboard_ icon.

Open a terminal and run the following git command:

```bash
git clone https://github.com/sKorpion19091/Semester-Assignment-COS214.git
```

## 2. Checkout the branch

Change to the repository directory on your computer (if you are not already there):

```
cd Semester-Assignment
```

Now create a branch using the `git checkout` command:

```
git checkout -b your-new-branch-name
```

For example:

```
git checkout -b my-name
```

(The name of the branch does not need to have the word _add_ in it, but it's a reasonable thing to include because the purpose of this branch is to add your name to a list.)

## Make necessary changes and commit those changes

<img align="right" width="450" src="https://firstcontributions.github.io/assets/Readme/git-status.png" alt="git status" />

If you go to the project directory and execute the command `git status`, you'll see there are changes.

Add those changes to the branch you just created using the `git add` command:

```
git add .
```

Now commit those changes using the `git commit` command:

```
git commit -m "Added header files"
```

## Push changes to GitHub

Push your changes using the command `git push`:

```
git push origin <add-your-branch-name>
```

replacing `<add-your-branch-name>` with the name of the branch you created earlier.

## Submit your changes for review

If you go to your repository on GitHub, you'll see a `Compare & pull request` button. Click on that button.

<img style="float: right;" src="https://firstcontributions.github.io/assets/Readme/compare-and-pull.png" alt="create a pull request" />

Now submit the pull request.

<img style="float: right;" src="https://firstcontributions.github.io/assets/Readme/submit-pull-request.png" alt="submit pull request" />


Someone will then merge the request.
