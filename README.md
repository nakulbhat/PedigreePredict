# Pedigree Charts and Linked Lists

This project implements a linked-list based data structure and algorithms for an active memory representation of a pedigree chart. It is designed to handle incomplete pedigrees effectively.

## Idea

The concept centers on probabilistic expectations for pedigree analysis. While inherited pedigrees can be calculated easily with known parental genotypes, challenges arise when parental information is missing. This program models the inheritance process mathematically, offering an implementation of that theory along with a user-friendly interface suitable for use by healthcare professionals.

## Features

- **Linked List Structure**: Efficiently represents complex pedigree relationships.
- **Incomplete Data Handling**: Supports analysis even when parental genotypes are unknown.
- **Probabilistic Inheritance Modeling**: Uses mathematical formulas to predict inherited traits.
- **User-Friendly Interface**: Designed with healthcare professionals in mind for ease of use.

## Installation

To install the project, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/nakulbhat/PedigreePredict.git

2. Build the project:

   ```bash
   make

3. Run Unit Tests:

   ```bash
   make test

4. Clean after make

   ```bash
   make clean

5. Run the Program

   ```bash
   ./PedigreePredict 

## Authorship

This project is being built and maintained by Nakul Bhat.

**Affiliation**: Department of Computer Science and Engineering, Manipal Institute of Technology, Manipal Academy of Higher Education, Manipal, Karnataka, India - 576104

**Contact**:
Please Reach out to me for queries and contributions.

- <nakul1.mitmpl2023@learner.manipal.edu>

## Contribution Guidelines

Contributions are the lifeblood of the open source community. Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add your feature'`).
5. Push to the branch (`git push origin feature/YourFeature`).
6. Open a pull request.

## FAQs / Troubleshooting

**Q: I encountered an error while running the tests. What should I do?**
A: Ensure all dependencies are installed and try running `make clean` before rebuilding. If the error still persists, then raise an issue with instructions to recreate the issue.

## Project Roadmap

- Develop a custom pedigree format and implement a file handler.
