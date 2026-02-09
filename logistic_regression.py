import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

def sigmoid(z):
    return 1/(1+np.exp(-z))

iris=load_iris()
x=iris.data
y=(iris.target==0).astype(int)

#test train split
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.3,random_state=42)

#initialize weight and bias and learning rate
w=np.zeros(x_train.shape[1])
b=0
lr=0.1

for _ in range(1000):
    z=np.dot(x_train,w)+b
    a=sigmoid(z)

    #derived weights bias
    dw=np.dot(x_train.T,(a-y_train))/len(y_train)
    db=np.sum(a-y_train)/len(y_train)

    w-=lr*dw
    b-=lr*db

final_z=np.dot(x_test,w)+b
pred=sigmoid(final_z)>=0.5

acc=np.mean(pred==y_test)
print(f"accuracy is : {acc}")