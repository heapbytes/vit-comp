from pymongo import MongoClient

# MongoDB connection details
mongo_url = "mongodb+srv://apoorvavpendse:1bPq47tDMc0eIRuI@cluster0.g8gibjo.mongodb.net/"  # Replace with your MongoDB connection URL
db_name = "test"  # Replace with your database name
collection_name = "useripcollections"  # Replace with your collection name

# Connect to MongoDB
client = MongoClient(mongo_url)
db = client[db_name]
collection = db[collection_name]

sample_document = collection.find_one()

# If there are documents in the collection
if sample_document:
    # Get all the parameter names (keys) of the document
    parameter_names = list(sample_document.keys())
    print("Parameter names in your collection:")
    print(parameter_names)
else:
    print("No documents found in the collection.")

# Update visitCount to 0 for all individual IP addresses
while True:
    print("Options:")
    print("1. Clean all")
    print("2. Clean visit count")
    print("3. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        # Connect to MongoDB
        client = MongoClient(mongo_url)
        db = client[db_name]
        collection = db[collection_name]

        # Delete all documents from the collection
        result = collection.delete_many({})

        # Print the number of deleted documents
        print(f"Deleted {result.deleted_count} documents from '{collection_name}' collection.")

        # Close the MongoDB connection
        client.close()

    elif choice == "2":
        # Connect to MongoDB
        client = MongoClient(mongo_url)
        db = client[db_name]
        collection = db[collection_name]

        # Update visitCount to 0 for all individual IP addresses
        result = collection.update_many(
            {"visitCount": {"$gt": 0}},  # Filter documents with visitCount greater than 0
            {"$set": {"visitCount": 0}}   # Set visitCount to 0 for matching documents
        )

        # Print the number of updated documents
        print(f"Updated {result.modified_count} documents. visitCount set to 0 for individual IP addresses.")

        # Close the MongoDB connection
        client.close()

    elif choice == "3":
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please enter 1, 2, or 3.")
