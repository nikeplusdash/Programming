package lab6;

class Banks {
    void getRateOfInterest(){
         System.out.println("Different Interest Rates for each bank");
    }
}

class SBI extends Banks {
    Float rate = 8f;
    void getRateOfInterest(){
        System.out.println("\n  /$$$$$$  /$$$$$$$  /$$$$$$\n" +
" /$$__  $$| $$__  $$|_  $$_/\n" +
"| $$  \\__/| $$  \\ $$  | $$  \n" +
"|  $$$$$$ | $$$$$$$   | $$  \n" +
" \\____  $$| $$__  $$  | $$  \n" +
" /$$  \\ $$| $$  \\ $$  | $$  \n" +
"|  $$$$$$/| $$$$$$$/ /$$$$$$\n" +
" \\______/ |_______/ |______/\n" +
"                            \n" +
"                            \n" +
"                            \n" +
"\n\n");
        System.out.println("Interest Rate: "+rate+"%\n\n\n\n\n");
    }
}

class ICICI extends Banks {
    Float rate = 7f;
    void getRateOfInterest(){
        System.out.println(" /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$\n" +
"|_  $$_/ /$$__  $$|_  $$_/ /$$__  $$|_  $$_/\n" +
"  | $$  | $$  \\__/  | $$  | $$  \\__/  | $$  \n" +
"  | $$  | $$        | $$  | $$        | $$  \n" +
"  | $$  | $$        | $$  | $$        | $$  \n" +
"  | $$  | $$    $$  | $$  | $$    $$  | $$  \n" +
" /$$$$$$|  $$$$$$/ /$$$$$$|  $$$$$$/ /$$$$$$\n" +
"|______/ \\______/ |______/ \\______/ |______/\n" +
"                                            " +

"\n\n");
         System.out.println("Interest Rate: "+rate+"%\n\n\n\n\n");
    }
}

class AXIS extends Banks {
    Float rate = 9f;
    void getRateOfInterest(){
        System.out.println("  /$$$$$$  /$$   /$$ /$$$$$$  /$$$$$$ \n" +
" /$$__  $$| $$  / $$|_  $$_/ /$$__  $$\n" +
"| $$  \\ $$|  $$/ $$/  | $$  | $$  \\__/\n" +
"| $$$$$$$$ \\  $$$$/   | $$  |  $$$$$$ \n" +
"| $$__  $$  >$$  $$   | $$   \\____  $$\n" +
"| $$  | $$ /$$/\\  $$  | $$   /$$  \\ $$\n" +
"| $$  | $$| $$  \\ $$ /$$$$$$|  $$$$$$/\n" +
"|__/  |__/|__/  |__/|______/ \\______/ \n" +
"                                      " +
"\n\n");
         System.out.println("Interest Rate: "+rate+"%\n\n\n\n\n");
    }
}

