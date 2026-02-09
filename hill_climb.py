import random

def objective_function(x):
    return -(x - 5)**2 + 20

def hill_climbing(max_iterations=1000, step_size=0.1):
    current_solution = random.uniform(-100, 100)
    current_score = objective_function(current_solution)
    
    print(f"Initialization: Starting x = {current_solution:.4f}, f(x) = {current_score:.4f}")
    
    for i in range(max_iterations):
        neighbors = [current_solution - step_size, current_solution + step_size]
        best_neighbor = None
        best_neighbor_score = float('-inf')
        
        for neighbor in neighbors:
            score = objective_function(neighbor)
            if score > best_neighbor_score:
                best_neighbor = neighbor
                best_neighbor_score = score
        
        if best_neighbor_score > current_score:
            current_solution = best_neighbor
            current_score = best_neighbor_score
        else:
            print(f"\nTermination: Local maximum reached at iteration {i}.")
            break
            
    return current_solution, current_score

if __name__ == "__main__":

    final_x, final_fx = hill_climbing()

    print("=" * 30)
    print("FINAL RESULT")
    print("=" * 30)
    print(f"x = {final_x}")
    print(f"f(x) = {final_fx}")