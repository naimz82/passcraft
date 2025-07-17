package passcraft;

import java.util.Scanner;

public class PasswordGenerator {
    private static final Scanner scanner = new Scanner(System.in);
    private static final String LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
    private static final String UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String NUMBERS = "0123456789";
    private static final String SYMBOLS = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    public static void generate() {
        System.out.println("\n=== Password Options ===");
        
        int length = getLength();
        boolean[] options = getCharacterOptions();
        
        String password = generatePassword(length, options);
        
        System.out.println("\n=== Generated Password ===");
        System.out.println(password);
        System.out.println("=========================");
    }

    public static int getLength() {
        System.out.print("Enter password length (min 8): ");
        int length;
        while (true) {
            length = PassCraft.getIntInput(1, Integer.MAX_VALUE);
            if (length >= 8) break;
            System.out.print("Password must be at least 8 characters: ");
        }
        return length;
    }

    private static boolean[] getCharacterOptions() {
        boolean[] options = new boolean[4];
        
        System.out.println("Character types to include:");
        options[0] = getYesNoInput("Lowercase letters? (y/n): ");
        options[1] = getYesNoInput("Uppercase letters? (y/n): ");
        options[2] = getYesNoInput("Numbers? (y/n): ");
        options[3] = getYesNoInput("Symbols? (y/n): ");
        
        // Verify at least one option selected
        while (!(options[0] || options[1] || options[2] || options[3])) {
            System.out.println("You must select at least one character type!");
            options[0] = getYesNoInput("Lowercase letters? (y/n): ");
            options[1] = getYesNoInput("Uppercase letters? (y/n): ");
            options[2] = getYesNoInput("Numbers? (y/n): ");
            options[3] = getYesNoInput("Symbols? (y/n): ");
        }
        
        return options;
    }

    private static boolean getYesNoInput(String prompt) {
        System.out.print(prompt);
        while (true) {
            String input = scanner.nextLine().trim().toLowerCase();
            if (input.equals("y")) return true;
            if (input.equals("n")) return false;
            System.out.print("Please enter 'y' or 'n': ");
        }
    }

    private static String generatePassword(int length, boolean[] options) {
        StringBuilder charPool = new StringBuilder();
        if (options[0]) charPool.append(LOWERCASE);
        if (options[1]) charPool.append(UPPERCASE);
        if (options[2]) charPool.append(NUMBERS);
        if (options[3]) charPool.append(SYMBOLS);

        StringBuilder password = new StringBuilder();
        for (int i = 0; i < length; i++) {
            int index = (int) (Math.random() * charPool.length());
            password.append(charPool.charAt(index));
        }
        
        return password.toString();
    }
}