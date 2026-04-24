# Step-by-Step Instructions

## PART 1: Create GitHub Repository

### Step 1: Go to GitHub.com
1. Visit https://github.com
2. Sign in (or create account if needed)

### Step 2: Create New Repository
1. Click **+** icon (top right) → **New repository**
2. Give it a name: `library-management-system`
3. Add description: `C++ Library Management System with Login`
4. Choose **Public** (so others can access)
5. **IMPORTANT**: Do NOT check "Add a README" or ".gitignore" (we already have them)
6. Click **Create repository**

### Step 3: GitHub will show you commands
You'll see something like:
```
git remote add origin https://github.com/YOUR_USERNAME/library-management-system.git
git branch -M main
git push -u origin main
```

---

## PART 2: Push Your Code to GitHub

### Open PowerShell and run:

```powershell
cd "C:\Users\WIN11\Documents\.vscode\sem 2\final project"
```

### Add GitHub remote:
```powershell
git remote add origin https://github.com/YOUR_USERNAME/library-management-system.git
```
*(Replace YOUR_USERNAME with your actual GitHub username)*

### Rename branch to main:
```powershell
git branch -M main
```

### Push to GitHub:
```powershell
git push -u origin main
```

**First time**, it may ask for authentication:
- Click the link or use GitHub authentication
- Allow access

---

## PART 3: Others Can Now Build Your Code

### Anyone can clone and run:

#### **Windows:**
```bash
git clone https://github.com/friovince153-dot/Library_management_system.git
cd library-management-system
mkdir build
cd build
cmake ..
cmake --build .
.\bin\Final_thesis.exe
```

#### **Linux:**
```bash
git clone https://github.com/friovince153-dot/Library_management_system.git
cd library-management-system
mkdir build
cd build
cmake ..
make
./bin/Final_thesis
```

#### **macOS:**
```bash
git clone https://github.com/friovince153-dot/Library_management_system.git
cd library-management-system
mkdir build
cd build
cmake ..
make
./bin/Final_thesis
```

---

## PART 4: Your Project Structure on GitHub

After pushing, GitHub will show:

```
library-management-system/
├── Book.cpp
├── Book.h
├── Library.cpp
├── Library.h
├── Loginandsignup.cpp
├── Loginandsignup.h
├── Final_project.cpp
├── CMakeLists.txt          ← Build instructions
├── .gitignore              ← Files to ignore
└── README.md               ← Instructions for users
```

**NO `.exe` files** (they're in .gitignore - clean!)

---

## PART 5: Make Updates (Later)

When you make changes to your code:

```powershell
cd "C:\Users\WIN11\Documents\.vscode\sem 2\final project"

git add .                               # Stage changes
git commit -m "Fixed bug in search"    # Describe what changed
git push                                # Upload to GitHub
```

---

## QUICK CHECKLIST

- [ ] Created GitHub account
- [ ] Created new repository
- [ ] Ran `git remote add origin https://...`
- [ ] Ran `git push -u origin main`
- [ ] Verified code appears on GitHub.com
- [ ] Tested cloning from another folder (optional)

---

## TROUBLESHOOTING

### "Remote already exists"
```powershell
git remote remove origin
git remote add origin https://github.com/YOUR_USERNAME/library-management-system.git
```

### "Permission denied"
- GitHub may ask for authentication
- Use GitHub Personal Access Token (Settings → Developer settings → Personal access tokens)

### Files still showing on GitHub
- Make sure `.gitignore` exists in project root
- Run `git status` to see what will be uploaded

---

## VERIFY IT WORKS

### From your current folder:
```powershell
cd "C:\Users\WIN11\Documents\.vscode\sem 2\final project"
git status
```

Should show:
```
On branch main
nothing to commit, working tree clean
```

### Visit GitHub:
Go to: `https://github.com/YOUR_USERNAME/library-management-system`

You should see all your source files! ✓

