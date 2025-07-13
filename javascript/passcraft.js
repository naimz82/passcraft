const fs = require('fs');
const readline = require('readline');

// Load the word list from txt file
const wordList = fs.readFileSync('../enpass-word-list.txt', 'utf-8')
  .split('\n')
  .filter(word => word.trim().length > 0);

// Create readline interface
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Main menu
function mainMenu() {
  console.log('\n=== PassCraft Generator ===');
  console.log('1. Generate Password');
  console.log('2. Generate Passphrase');
  console.log('3. Exit');

  rl.question('Choose an option (1-3): ', (choice) => {
    switch (choice) {
      case '1':
        passwordOptions();
        break;
      case '2':
        passphraseOptions();
        break;
      case '3':
        rl.close();
        break;
      default:
        console.log('Invalid choice. Please try again.');
        mainMenu();
    }
  });
}

// Password generation options
function passwordOptions() {
  console.log('\n=== Password Options ===');
  
  rl.question('Enter password length (min 8): ', (length) => {
    const passLength = parseInt(length);
    
    if (isNaN(passLength) || passLength < 8) {
      console.log('Invalid length. Minimum is 8 characters.');
      return passwordOptions();
    }

    const options = {};
    
    const askOption = (optionName, question, callback) => {
      rl.question(question, (answer) => {
        options[optionName] = answer.toLowerCase() === 'y';
        callback();
      });
    };

    askOption('lowercase', 'Include lowercase letters? (y/n): ', () => {
      askOption('uppercase', 'Include uppercase letters? (y/n): ', () => {
        askOption('numbers', 'Include numbers? (y/n): ', () => {
          askOption('symbols', 'Include symbols? (y/n): ', () => {
            if (!Object.values(options).some(v => v)) {
              console.log('You must select at least one character type.');
              return passwordOptions();
            }
            generatePassword(passLength, options);
          });
        });
      });
    });
  });
}

// Passphrase generation options
function passphraseOptions() {
  console.log('\n=== Passphrase Options ===');
  
  rl.question('Enter number of words (min 4): ', (count) => {
    const wordCount = parseInt(count);
    
    if (isNaN(wordCount)) {
      console.log('Please enter a valid number.');
      return passphraseOptions();
    }
    
    if (wordCount < 4) {
      console.log('Minimum is 4 words for security.');
      return passphraseOptions();
    }

    generatePassphrase(wordCount);
  });
}

// Generate password
function generatePassword(length, options) {
  let chars = '';
  const characterSets = {
    lowercase: 'abcdefghijklmnopqrstuvwxyz',
    uppercase: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
    numbers: '0123456789',
    symbols: '!@#$%^&*()_+-=[]{}|;:,.<>?'
  };

  for (const [type, include] of Object.entries(options)) {
    if (include) chars += characterSets[type];
  }

  let password = '';
  for (let i = 0; i < length; i++) {
    password += chars.charAt(Math.floor(Math.random() * chars.length));
  }

  console.log('\n=== Generated Password ===');
  console.log(password);
  console.log('=========================');
  
  mainMenu();
}

// Generate passphrase
function generatePassphrase(wordCount) {
  let passphrase = '';
  
  for (let i = 0; i < wordCount; i++) {
    const randomIndex = Math.floor(Math.random() * wordList.length);
    passphrase += wordList[randomIndex];
    if (i < wordCount - 1) passphrase += ' ';
  }

  console.log('\n=== Generated Passphrase ===');
  console.log(passphrase);
  console.log('===========================');
  
  mainMenu();
}

// Start the application
console.log('Welcome to PassCraft!');
mainMenu();