class Student {

private:

    //class attributes
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[5];
    Degree degree;

public:

    //accessors
    string Student::getStudentId();
    string Student::getFirstName();
    string Student::getLastName();
    string Student::getEmailAddress();
    int Student::getAge();
    int[] Student::getStudentId();
};