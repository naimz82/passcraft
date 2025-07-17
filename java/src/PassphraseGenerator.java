package passcraft;

import java.util.List;
import java.util.Random;

public class PassphraseGenerator {
    private static final Random random = new Random();

    public static void generate(List<String> wordList) {
        System.out.println("\n=== Passphrase Options ===");
        
        int wordCount = getWordCount();
        String passphrase = generatePassphrase(wordList, wordCount);
        
        System.out.println("\n=== Generated Passphrase ===");
        System.out.println(passphrase);
        System.out.println("===========================");
    }

    public static int getWordCount() {
        System.out.print("Enter number of words (min 4): ");
        int count;
        while (true) {
            count = PassCraft.getIntInput(1, Integer.MAX_VALUE);
            if (count >= 4) break;
            System.out.print("Passphrase must have at least 4 words: ");
        }
        return count;
    }

    private static String generatePassphrase(List<String> wordList, int wordCount) {
        StringBuilder passphrase = new StringBuilder();
        
        for (int i = 0; i < wordCount; i++) {
            if (i > 0) passphrase.append(" ");
            int index = random.nextInt(wordList.size());
            passphrase.append(wordList.get(index));
        }
        
        return passphrase.toString();
    }
}