Inheritance, Interfaces and Packages.
Methods for organizing classes and class behaviors

Inheritance.
When a class is written we specify how a class is different from another class
while giving dynamic access to info contained in those other classes.
Classes are arranged in a hierachy.
Subclasses inherit all methods from their superclasses, we dont need to redifine
it.
When developing classes in a hierarchy, we factor out infomation common to 
mulitple classes in superclasses and reuse superclasses information obver and over
again.
Changing or inserting a class further up the hierarchy automatically changes
behavior of lower classes.
Overidding a method is whereby a subclass defines a method that has already been
defined by a superclass.
The method found first(bottom, method of subclass) is executed.
Multiple inheritance -> Classes can have more than one superclass and can inherit combined variables and
methods from all those superclasses.
Java doesnt suppor multiple inheritance.
Interfaces and packages.
Methods for implementing and designing groups of classes and class behavior.
An interface is a collection of methods, names without actual definitons that
indicate a set of behaviors a class gets from its superclasses.
Packages are a way for java to group together related classes and interfaces. Modular
groups of classes are only availabe when needed, this is to eliminate confilicts 
between class names.
