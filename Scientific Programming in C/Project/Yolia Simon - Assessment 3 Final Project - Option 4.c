/*
 * Assessment 3 for PHY2027
 * Author: Yolia Simon
 * Date: 28/11/2024
*/

/*
 * Program description: This C program simulates a random walk of a particle in one, two, or three dimensions.
 * The user provides inputs such as the number of steps, lattice spacing, time step, diffusion constant, and the
 * choice of dimensions. There is also the option for self-avoidance in 2D and 3D, where it cannot revisit previously
 * occupied lattice points. The program generates the particle's position at each step, storing the data in a CSV file.
 * This output can then be visualized using Python or other plotting tools to analyze the walk's behaviour over time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes here

void random_walk_1D(int steps, double dx, double dt, double D, const char *filename);

void random_walk_2D(int steps, double dx, double dt, double D, const char *filename, bool self_avoiding);

void random_walk_3D(int steps, double dx, double dt, double D, const char *filename, bool self_avoiding);

bool is_visited(int x, int y, int z, int **visited, int visited_count);

void print_py_code(int dimension);

int main() {
    int steps, dimension;
    double dx, dt, D;
    char filename[100], mode[20], choice[10]; //arrays to store user responses
    bool self_avoiding = false;
    bool valid_filename = false;

    printf("This is a simulation of a random walk of a particle. You will be able to enter the parameters you want and a csv file will be generated. This output can then be visualized using Python or other plotting tools to analyze the walk's behaviour over time.\n");

    // User inputs
    do {
    printf("\nEnter the number of steps: ");

    // Checks if input is valid
    if (scanf("%d", &steps) != 1 || steps <= 0) {
        fprintf(stderr, "Invalid input! Number of steps must be a positive integer.\n");

        // Clear the incorrect input
        while (getchar() != '\n');
        } else {
            break; // Exit loop if input is valid
            }
    } while (1);


    do {
    printf("\nEnter lattice spacing (dx): ");

    if (scanf("%lf", &dx) != 1 || dx <= 0) {
        fprintf(stderr, "Invalid input! dx must be a positive integer.\n");

        while (getchar() != '\n');
        } else {
            break;
            }
    } while (1);


    do {
    printf("\nEnter time step (dt): ");
    if (scanf("%lf", &dt) != 1 || dt <= 0) {
        fprintf(stderr, "\nInvalid input! dt must be a positive integer.\n");

        while (getchar() != '\n');
        } else {
            break;
            }
    } while (1);

    do {
    printf("\nEnter diffusion constant (D): ");
    if (scanf("%lf", &D) != 1 || D <= 0) {
        fprintf(stderr, "\nInvalid input! D must be a positive integer.\n");

        while (getchar() != '\n');
        } else {
            break;
            }
    } while (1);

    do {
    printf("\nEnter dimension (1 for 1D, 2 for 2D, 3 for 3D): \n");
    if (scanf("%d", &dimension) != 1 || (dimension != 1 && dimension != 2 && dimension != 3)) {
        fprintf(stderr, "\nInvalid input! Dimension must be either 1, 2, or 3.\n");

        while (getchar() != '\n');
        } else {
            break;
            }
    } while (1);

    if (dimension > 1) {
        printf("\nEnable self-avoiding random walk? (yes or no): ");
        scanf("%s", mode);
        if (strcmp(mode, "yes") == 0) {
            self_avoiding = true;
        } else if (strcmp(mode, "no") != 0) {
            fprintf(stderr, "\nInvalid input! Please type either 'yes' or 'no'.\n");
            return 1;
        }
    }


    while (!valid_filename) {
        printf("\nEnter output filename including .csv (e.g., output.csv): ");
        scanf("%s", filename);

    // Check if the string ends with ".csv"
        if (strlen(filename) >= 4 && strcmp(&filename[strlen(filename) - 4], ".csv") == 0) {
            valid_filename = true; // Filename is valid
        } else {
            printf("Invalid filename! Must be at least 4 characters long. Make sure it ends with '.csv'.\n");
            }
        }

    printf("\n\nRunning simulation, please wait...\n\n");

    // Run the simulation based on dimensions
    switch (dimension) {
        case 1:
            random_walk_1D(steps, dx, dt, D, filename);
            break;
        case 2:
            random_walk_2D(steps, dx, dt, D, filename, self_avoiding);
            break;
        case 3:
            random_walk_3D(steps, dx, dt, D, filename, self_avoiding);
            break;
    }

    printf("\nSimulation complete! Data has been saved to %s\n\n", filename);

    printf("\nWould you like a Python script that visualises your data? (yes or no)\n");
    while (1) {
        if (scanf("%9s", choice) != 1) {
            // If there's an error with scanf, prompt again
            printf("Invalid input. Please enter 'yes' or 'no': ");
            while (getchar() != '\n');
            continue;
        }

        // Check if the choice is valid
        if (strcmp(choice, "yes") == 0) {
            print_py_code(dimension);
            break;
        } else if (strcmp(choice, "no") == 0) {
            printf("\nAction cancelled.\n");
            break;
        } else {
            printf("\nInvalid input! Please answer with 'yes' or 'no': ");
            while (getchar() != '\n');
        }
    }

    printf("\n\nThank you for using this simulation~\n\n");

    return 0;
}


// 1D Random Walk
void random_walk_1D(int steps, double dx, double dt, double D, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    fprintf(file, "Step,Position\n");

    int position = 0; //starting position
    double p = D * dt / (dx * dx); //diffusion equation

    for (int i = 0; i < steps; i++) {
        double r = (double) rand() / RAND_MAX; // random number generation
        if (r < p) {
            position += 1; // particle moves right
        } else if (r < 2 * p) { // particle moves left
            position -= 1;
        }
        fprintf(file, "%d,%d\n", i, position);
    }

    fclose(file);
}

// 2D Random Walk
void random_walk_2D(int steps, double dx, double dt, double D, const char *filename, bool self_avoiding) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    fprintf(file, "Step,X,Y\n");

    int x = 0, y = 0;
    int visited_count = 0;
    int **visited = NULL;

    // allocating memory for each row if self_avoiding is true
    if (self_avoiding) {
        visited = malloc(steps * sizeof(int*));
        if (!visited) {
            perror("Memory allocation failed for visited array");
            fclose(file);
            exit(1);
        }
        for (int i = 0; i < steps; i++) {
            visited[i] = malloc(2 * sizeof(int));
            if (!visited[i]) {
                perror("Memory allocation failed for visited sub-array");
                fclose(file);
                exit(1);
            }
        }

        // records the starting position as 'visited'
        visited[visited_count][0] = x;
        visited[visited_count][1] = y;
        visited_count++;
    }

    double p = D * dt / (dx * dx);

    for (int i = 0; i < steps; i++) {
        double r = (double) rand() / RAND_MAX;
        int dx = 0, dy = 0;

        if (r < p) dx = 1; // particle moves right
        else if (r < 2 * p) dx = -1; //particle moves left
        else if (r < 3 * p) dy = 1; // particle moves up
        else if (r < 4 * p) dy = -1; // particle moves down

        if (self_avoiding && is_visited(x + dx, y + dy, 0, visited, visited_count)) {
            continue;
        }

        x += dx;
        y += dy;

        if (self_avoiding) {
            visited[visited_count][0] = x;
            visited[visited_count][1] = y;
            visited_count++;
        }

        fprintf(file, "%d,%d,%d\n", i, x, y);
    }

    // Free memory for self-avoiding walks
    if (self_avoiding) {
        for (int i = 0; i < steps; i++) {
            free(visited[i]);
        }
        free(visited);
    }

    fclose(file);
}

//3D random walk
void random_walk_3D(int steps, double dx, double dt, double D, const char *filename, bool self_avoiding) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    fprintf(file, "Step,X,Y,Z\n");

    int x = 0, y = 0, z = 0;
    int visited_count = 0;
    int **visited = NULL;

    // Allocate memory for visited array only if self-avoiding is enabled
    if (self_avoiding) {
        visited = malloc(steps * sizeof(int*));
        if (!visited) {
            perror("Memory allocation failed for visited array");
            fclose(file);
            exit(1);
        }
        for (int i = 0; i < steps; i++) {
            visited[i] = malloc(3 * sizeof(int));
            if (!visited[i]) {
                perror("Memory allocation failed for visited sub-array");
                // Free previously allocated memory before exiting
                for (int j = 0; j < i; j++) {
                    free(visited[j]);
                }
                free(visited);
                fclose(file);
                exit(1);
            }
        }

        // Record the starting position as visited
        visited[visited_count][0] = x;
        visited[visited_count][1] = y;
        visited[visited_count][2] = z;
        visited_count++;
    }

    double p = D * dt / (dx * dx);

    // Perform the random walk
    for (int i = 0; i < steps; i++) {
        double r = (double) rand() / RAND_MAX;
        int dx = 0, dy = 0, dz = 0;

        // Determine the direction of movement along x, y or z axis
        if (r < p) dx = 1;
        else if (r < 2 * p) dx = -1;
        else if (r < 3 * p) dy = 1;
        else if (r < 4 * p) dy = -1;
        else if (r < 5 * p) dz = 1;
        else if (r < 6 * p) dz = -1;

        // Check for self-avoidance
        if (self_avoiding && is_visited(x + dx, y + dy, z + dz, visited, visited_count)) {
            continue; // Skip this step if it revisits a position
        }

        // Update position
        x += dx;
        y += dy;
        z += dz;

        // Record the new position in visited array if self-avoiding
        if (self_avoiding) {
            visited[visited_count][0] = x;
            visited[visited_count][1] = y;
            visited[visited_count][2] = z;
            visited_count++;
        }

        // Write the step and position to the file
        fprintf(file, "%d,%d,%d,%d\n", i, x, y, z);
    }

    // Free memory for self-avoiding walks
    if (self_avoiding) {
        for (int i = 0; i < steps; i++) {
            free(visited[i]);
        }
        free(visited);
    }

    fclose(file);
}

// Helper function to check if a position is visited
bool is_visited(int x, int y, int z, int **visited, int visited_count) {
    for (int i = 0; i < visited_count; i++) {
        if (visited[i][0] == x && visited[i][1] == y && visited[i][2] == z) {
            return true;
        }
    }
    return false;
}

void print_py_code(int dimension) {

    FILE *fptr = fopen("visualisation_python_code.txt", "w");

    //checks if the file opened correctly
    if (fptr == NULL) {
        fprintf(stderr, "Error opening the file for writing.\n");
        exit(1);
    }

    switch (dimension) {
        case 1:
            fprintf(fptr, "-Python code-\n\n\n"
                    "import matplotlib.pyplot as plt\n"
                    "import pandas as pd\n\n"
                    "df = pd.read_csv('test.csv')\n\n"
                    "# Plot the position as a function of step\n"
                    "plt.figure(figsize=(8, 6))\n"
                    "plt.plot(df['Step'], df['Position'], label='Position')\n"
                    "plt.xlabel('Step')\n"
                    "plt.ylabel('Position')\n"
                    "plt.title('1D Random Walk')\n"
                    "plt.grid(True)\n"
                    "plt.legend()\n"
                    "plt.show()\n"
                    );
            printf("Python script saved to visualisation_python_code.txt");
            break;
        case 2:
            fprintf(fptr, "-Python code-\n\n\n"
                    "import matplotlib.pyplot as plt\n"
                    "import pandas as pd\n\n"
                    "df = pd.read_csv('test.csv')\n\n"
                    "# Plot the position as a function of step\n"
                    "plt.figure(figsize=(8, 8))\n"
                    "plt.plot(df['X'], df['Y'], label='Trajectory', marker='o', markersize=3)\n"
                    "plt.xlabel('X')\n"
                    "plt.ylabel('Y')\n"
                    "plt.title('2D Random Walk')\n"
                    "plt.grid(True)\n"
                    "plt.legend()\n"
                    "plt.show()\n"
                    );
            printf("\n\nPython script saved to visualisation_python_code.txt");
            break;
        case 3:
            fprintf(fptr, "-Python code-\n\n\n"
                    "import matplotlib.pyplot as plt\n"
                    "from mpl_toolkits.mplot3d import Axes3D\n"
                    "import pandas as pd\n\n"
                    "df = pd.read_csv('test.csv')\n\n"
                    "# Create a 3D plot\n"
                    "fig = plt.figure(figsize=(10, 8))\n"
                    "ax = fig.add_subplot(111, projection='3d')\n\n"
                    "# Plot the trajectory in 3D\n"
                    "ax.plot(df['X'], df['Y'], df['Z'], label='Trajectory', marker='o', markersize=3)\n"
                    "ax.set_xlabel('X')\n"
                    "ax.set_ylabel('Y')\n"
                    "ax.set_zlabel('Z')\n"
                    "ax.set_title('3D Random Walk')\n"
                    "plt.legend()\n"
                    "plt.show()\n"

                    );
            printf("Python script saved to visualisation_python_code.txt");
            break;
        default:
            printf("Invalid dimension.\n");
            exit(1);
    }

    fclose(fptr);

    printf("\nTo visualise the data, please copy and paste the python code into your favourite code editor (e.g: Visual Studio Code). In the code, make sure to change 'test.csv' to the name of your own csv file.");
}
