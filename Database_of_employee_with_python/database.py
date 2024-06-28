'''
Write a python code that manage a database for employees. Each
employee has a unique ID and has the following data:
Name, Job and Salary. The system shall allow:
1-Add new employee
2-Print employee data
3-remove employee from the system
4- update
'''
class Employee_Database:
    def __init__(self):
        #Init dict
        self.employees = {}
        #Init ID count
        self.next_id = 1  
    # This fun use to add name,job and salary for new employee
    def Add_Employee(self, name, job, salary):
        employee_id = self.next_id
        self.employees[employee_id] = {'name': name, 'job': job, 'salary': salary}
        self.next_id += 1
        print(f"Employee added successfully with ID: {employee_id}")

     # This fun use to print data from employee
    def Print_Employee_Data(self, employee_id):
        if employee_id in self.employees:
            emp = self.employees[employee_id]
            print("___________________")
            print(f"Employee ID: {employee_id}")
            print(f"Name: {emp['name']}")
            print(f"Job: {emp['job']}")
            print(f"Salary: {emp['salary']}")
            print("___________________")
        else:
            print(f"Employee with ID {employee_id} not found")

    # This fun use to remove data from employee
    def Remove_Employee(self, employee_id):
        if employee_id in self.employees:
            del self.employees[employee_id]
            print(f"Employee with ID {employee_id} removed successfully")
        else:
            print(f"Employee with ID {employee_id} not found")
            
    # This fun use to update data from employee
    def Update_Employee(self, employee_id, name=None, job=None, salary=None):
        if employee_id in self.employees:
            emp = self.employees[employee_id]
            if name:
                emp['name'] = name
            if job:
                emp['job'] = job
            if salary:
                emp['salary'] = salary
            print(f"Employee ID {employee_id} updated successfully")
        else:
            print(f"Employee ID {employee_id} not found")


# object of class
ED = Employee_Database()
while(1):
    print("*******Welcome our system*******")
    print("1-Add new employee\n2-Print employee data\n3-Remove employee from the system\n4-Update")
    choice=int(input("Please Enter your choice:"))
    if(choice == 1):
        name=str(input("Please Enter Name:"))
        job =str(input("Please Enter job:"))
        Salary=int(input("Please Enter salary:"))
        ED.Add_Employee(name,job,Salary)
    elif(choice == 2):
        ID=int(input("Please Enter ID:"))
        ED.Print_Employee_Data(ID)
    elif(choice == 3):
        ID=int(input("Please Enter ID:"))
        ED.Remove_Employee(ID)
    elif(choice == 4):
        ID=int(input("Please Enter ID:"))
        name=str(input("Please Enter Name:"))
        job =str(input("Please Enter job:"))
        Salary=int(input("Please Enter salary:"))
        ED.Update_Employee(ID,name,job,Salary)
    else:
        print("Wrong choice please try again")        


