package lab9;

import java.util.Scanner;

public class Lab9 {
    public static Integer getWords(String s) {
        Integer words = 1;
        if (s.length() == 0) return 0;
        for(Integer x = 0;x<s.length();x++)
            if(s.charAt(x) == ' '&& s.charAt(x+1) != ' ')  words++;
        return words;
    }
    
    public static Integer getVowels(String s) {
        Integer vowels = 0;
        String vowelStr = "aeiouAEIOU";
        for(Integer x = 0;x<s.length();x++)
            if(vowelStr.indexOf(s.charAt(x)) != -1) vowels++;
        return vowels;
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s;
        Integer characters = 0,words = 0,lines = 0,vowels = 0;
        while(!(s = in.nextLine()).equals("...")) {
            characters += s.length();
            lines++;
            words += getWords(s);
            vowels += getVowels(s);
            if(s.contains("...")) break;
        }
        System.out.printf("Characters: %d\nWords: %d\nLines: %d\nVowels: %d\n", characters,words,lines,vowels);
        in.close();
    }
}

/*
Hi,
This is Agent 69 trapped on Planet Exo-Vertigo 1747.
We need urgent help. The clowns have breached into our data and have gained access to the Security Frame.
From the current situation, it seems they have passed through Level 9.
To be continue...
*/