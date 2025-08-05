# Airgead Banking App

## Project Overview

The **Airgead Banking App** is a C++ console application that calculates and displays the growth of an investment over time. Users input their initial investment amount, monthly deposit (optional), annual interest rate, and the number of years for the investment. The program then calculates and displays detailed annual reports of the investment with and without additional monthly deposits.

This project solves a common financial problem: understanding how compound interest affects savings and investments over time. It gives users a clear, formatted summary of how their money grows, helping them make informed financial decisions.

Few have put it more eloquently than Einstein (while there is no verified source, the sentiment still stands): 
      *"Compound interest is the eighth wonder of the world. He who understands it, earns it… he who doesn’t, pays it."*

---

## Reflection

### What did you do particularly well?

I've implemented clean, modular code with a strong separation of responsibilities. The logic for calculations was clearly abstracted into functions and the user input/output flow was intuitive and error-resistant. I also ensured that the application consistently formatted the output into aligned tables, enhancing user readability.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I could improve error handling, particularly in validating user inputs to prevent invalid values like negative interest rates or non-numeric input. Additionally, unit testing or logging could vastly improve reliability and traceability. These improvements would make the app more secure and robust against misuse. I'm considering these additional features for the second phase.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging part was designing the logic to calculate compound interest with monthly deposits and to format the results neatly in tabular form. I overcame these challenges by using the debugger to step through problems manually, utilising helper functions, referring to official C++ documentation (cppreference.com), and testing my own edge cases to ensure the calculations and formatting aligned with client expectations.

### What skills from this project will be particularly transferable to other projects or course work?

This project sharpened my skills in a few areas:

- Object-oriented design and modular programming in C++ (admittedly not one of my standard languages)
- Using Git and GitHub effectively for version control
- Formatting console output in visually-pleasing, user-friendly manners
- Handling user input and validating data
- Leveraging IDE features in Visual Studio to debug and refactor my code 

I find these skills to be directly applicable to future coursework and professional development in a production environment, particularly in system-level programming and application development.

### How did you make this program maintainable, readable, and adaptable?

The app demonstrates consistent naming conventions, clear syntax, proper indentation, and modular, well-structured functions. I added inline comments to clarify complex logic and organized all calculation functionality into a dedicated class, making the app easy to scale or adapt (e.g., for different compounding intervals or currencies). I also configured a .gitignore file to exclude unnecessary build and cache files, keeping the repository clean and professional.

