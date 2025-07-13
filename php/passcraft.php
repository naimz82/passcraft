<?php
// Load word list from shared file
$wordList = file('../enpass-word-list.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

// Character sets
$characterSets = [
    'lowercase' => 'abcdefghijklmnopqrstuvwxyz',
    'uppercase' => 'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
    'numbers' => '0123456789',
    'symbols' => '!@#$%^&*()_+-=[]{}|;:,.<>?'
];

function clearScreen() {
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN') {
        system('cls');
    } else {
        system('clear');
    }
}

function showBanner() {
    clearScreen();
    echo "================================\n";
    echo "      PASSCRAFT GENERATOR       \n";
    echo "================================\n\n";
}

function mainMenu() {
    global $wordList;
    
    showBanner();
    echo "Main Menu:\n";
    echo "1. Generate Password\n";
    echo "2. Generate Passphrase\n";
    echo "3. Exit\n";
    
    $choice = readline("Choose an option (1-3): ");
    
    switch ($choice) {
        case '1':
            passwordOptions();
            break;
        case '2':
            passphraseOptions();
            break;
        case '3':
            exit("\nGoodbye!\n");
        default:
            echo "Invalid choice. Please try again.\n";
            sleep(1);
            mainMenu();
    }
}

function passwordOptions() {
    global $characterSets;
    
    showBanner();
    echo "PASSWORD OPTIONS\n\n";
    
    // Get password length
    $length = (int)readline("Enter password length (min 8): ");
    if ($length < 8) {
        echo "Minimum length is 8 characters.\n";
        sleep(1);
        return passwordOptions();
    }
    
    // Get character types
    $options = [];
    foreach ($characterSets as $type => $chars) {
        $answer = strtolower(readline("Include $type? (y/n): "));
        $options[$type] = ($answer === 'y');
    }
    
    // Validate at least one option selected
    if (!in_array(true, $options, true)) {
        echo "You must select at least one character type.\n";
        sleep(1);
        return passwordOptions();
    }
    
    generatePassword($length, $options);
}

function generatePassword($length, $options) {
    global $characterSets;
    
    $chars = '';
    foreach ($options as $type => $include) {
        if ($include) {
            $chars .= $characterSets[$type];
        }
    }
    
    $password = '';
    $maxIndex = strlen($chars) - 1;
    
    for ($i = 0; $i < $length; $i++) {
        $password .= $chars[random_int(0, $maxIndex)];
    }
    
    showBanner();
    echo "=== GENERATED PASSWORD ===\n";
    echo $password . "\n";
    echo "==========================\n\n";
    
    readline("Press Enter to continue...");
    mainMenu();
}

function passphraseOptions() {
    global $wordList;
    
    showBanner();
    echo "PASSPHRASE OPTIONS\n\n";
    
    $count = (int)readline("Enter number of words (min 4): ");
    if ($count < 4) {
        echo "Minimum is 4 words for security.\n";
        sleep(1);
        return passphraseOptions();
    }
    
    generatePassphrase($count);
}

function generatePassphrase($wordCount) {
    global $wordList;
    
    $selectedWords = [];
    $maxIndex = count($wordList) - 1;
    
    for ($i = 0; $i < $wordCount; $i++) {
        $selectedWords[] = $wordList[random_int(0, $maxIndex)];
    }
    
    $passphrase = implode(' ', $selectedWords);
    
    showBanner();
    echo "=== GENERATED PASSPHRASE ===\n";
    echo $passphrase . "\n";
    echo "===========================\n\n";
    
    readline("Press Enter to continue...");
    mainMenu();
}

// Start the application
mainMenu();