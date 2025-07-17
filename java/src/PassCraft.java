package passcraft;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class PassCraft {
    private static List<String> wordList;
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        try {
            // Load word list
            wordList = Files.readAllLines(Paths.get("../enpass-word-list.txt"));
            System.out.println("Loaded " + wordList.size() + " words");
            
            while (true) {
                showMainMenu();
            }
        } catch (IOException e) {
            System.err.println("Error loading word list: " + e.getMessage());
            System.exit(1);
        }
    }

    private static void showMainMenu() {
        System.out.println("\n=== PassCraft Generator ===");
        System.out.println("1. Generate Password");
        System.out.println("2. Generate Passphrase");
        System.out.println("3. Exit");
        System.out.print("Choose an option (1-3): ");

        int choice = getIntInput(1, 3);

        switch (choice) {
            case 1:
                PasswordGenerator.generate();
                break;
            case 2:
                PassphraseGenerator.generate(wordList);
                break;
            case 3:
                System.out.println("Goodbye!");
                System.exit(0);
        }
    }

    public static int getIntInput(int min, int max) {
        while (true) {
            try {
                int input = Integer.parseInt(scanner.nextLine());
                if (input >= min && input <= max) {
                    return input;
                }
                System.out.print("Invalid input. Please enter a number between " + min + "-" + max + ": ");
            } catch (NumberFormatException e) {
                System.out.print("Invalid input. Please enter a number: ");
            }
        }
    }
}