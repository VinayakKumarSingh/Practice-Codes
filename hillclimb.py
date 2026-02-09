def hillclimb(start,func,step=0.1,max_iter=1000):
    curr=start;
    curr_val=func(curr)

    for i in range(max_iter):
        pos_neighbor=curr+step
        pos_val=func(pos_neighbor)

        neg_neighbor=curr-step
        neg_val=func(neg_neighbor)

        if(pos_val>curr_val and pos_val>=neg_val):
            curr=pos_neighbor
            curr_val=pos_val
        
        elif(neg_val>curr_val and neg_val>pos_val):
            curr=neg_neighbor
            curr_val=neg_val
        else:  
            break
    
    return curr,curr_val

while(True):
    func_str=input("Enter a Function with a single variable x")
    try:
        x=0;
        eval(func_str)
        break
    except Exception as e:
        print(f"Invalid Input {e}")
    
func=lambda x:eval(func_str)

while(True):
    start_str=input("enter starting value for x")
    try:
        start=float(start_str)
        break
    except
        print("Enter valid x value Nigga")
    
local_val,local_max=hillclimb(start,func)

print("Maxima occurs at ",local_val)
print("Maxima is ",local_max)
