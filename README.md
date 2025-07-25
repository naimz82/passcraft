# PassCraft - Multi-Language Password/Passphrase Generator

**PassCraft** is a multi-language password and passphrase generator available in **C++**, **Java**, **JavaScript**, **PHP**, and **Python**. Each implementation runs in the **Command Line Interface (CLI)**, allowing users to generate secure passwords or memorable passphrases with customizable options.

> [!NOTE]
> Most of the examples below are for a Linux/MacOS environment. Windows users will need to adjust accordingly.

### 📦 Project Structure
```text
passcraft/  
├── c++/          # C++ implementation  
├── java/         # Java implementation  
├── javascript/   # JavaScript (Node.js) implementation  
├── php/          # PHP implementation  
└── python/       # Python implementation  
```

### 🚀 Features
✔ **Generate random passwords** (with customizable length & character sets)  
✔ **Generate random passphrases** (with word count selection)  
✔ **Developed in multiple programming languages** (C++, Java, JavaScript, PHP, Python)  
✔ **Simple CLI-based execution** (customize your own GUI)  

### 🛠 Setup & Usage Instructions
#### 1️⃣ C++
**Requirements**
- GCC/G++ (GNU Compiler Collection)
- Linux/macOS (already has GCC) or Windows (via MinGW)
**Steps**
1. Navigate to the c++/ directory.
2. Preprocess the Word List  
Run these commands in the `passcraft/c++/` directory to convert `enpass-word-list.txt` into a C++ header:  
 ```bash
echo "const std::vector<std::string> wordList = {" > wordlist.h
sed 's/^/    \"/;s/$/\",/' ../enpass-word-list.txt >> wordlist.h
echo "};" >> wordlist.h
```
3. Compile the program:
```sh
g++ -std=c++17 passcraft.cpp -o passcraft
```
4. Run the executable:
```sh
./passcraft
```

#### 2️⃣ Java
**Requirements**
- Java JDK (≥ 8)
- (Optional) An IDE like IntelliJ or Eclipse
**Steps**
1. Navigate to the `java/` directory.
2. Compile the Java files in `src`:
```sh
javac src/*.java -d bin/
```
3. Run the program:
```sh
java -cp bin passcraft.PassCraft
```

#### 3️⃣ JavaScript (Node.js)
**Requirements**
- Node.js (≥ v14)
**Steps**
1. Navigate to the javascript/ directory.
2. Install dependencies (if any):
```sh
npm install
```
3. Run the script:
```sh
node passcraft.js
```

#### 4️⃣ PHP
**Requirements**
- PHP CLI (≥ 7.4)
**Steps**
1. Navigate to the php/ directory.
2. Run the script directly:
```sh
php passcraft.php
```

#### 5️⃣ Python
**Requirements**
- Python (≥ 3.6)
**Steps**
1. Navigate to the python/ directory.
2. Run the script:
```sh
python3 passcraft.py
```
(or `python passcraft.py` if needed)

### 🤝 Contributing
Contributions are welcomed! If you want to:
- **Add a new language** (e.g., Rust, Go)
- **Enhance CLI UX** (colors, better prompts)
- Other improvements

**Steps:**
1. Fork the repo
2. Create a new branch (`git checkout -b feature/new-language`)
3. Commit changes (`git commit -m "Add Rust implementation"`)
4. Push to the branch (`git push origin feature/new-language`)
5. Open a Pull Request

### 📜 License
This project is MIT Licensed. Feel free to use, modify, and distribute it!

### 🔐 Security Note
⚠ **This tool is for educational purposes.**
For real-world security, consider using established tools like:
- KeePassXC (Password Manager)
- Bitwarden (Open-source Vault)
- Diceware (For truly random passphrases)

**🌟 Enjoy PassCraft!**  
If you find this useful, **give it a ⭐ on GitHub!** 🚀