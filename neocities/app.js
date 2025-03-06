// Your Firebase config from Firebase Console
const firebaseConfig = {
  apiKey: "AIzaSyCiro2q408vBSUoL_qyMa4LfjGkQ-5AjG4",
  authDomain: "neocities-blog-7e2a3.firebaseapp.com",
  projectId: "neocities-blog-7e2a3",
  storageBucket: "neocities-blog-7e2a3.firebasestorage.app",
  messagingSenderId: "50550981769",
  appId: "1:50550981769:web:b33e35d70de659ef0f7258"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();
const auth = firebase.auth();

// Function to log in as the owner
function login() {
  let email = document.getElementById("email").value;
  let password = document.getElementById("password").value;

  firebase.auth().signInWithEmailAndPassword(email, password)
  .then((userCredential) => {
      console.log("Login successful:", userCredential);
      document.getElementById("postForm").style.display = "block";
      document.getElementById("logoutBtn").style.display = "block";
  })
  .catch((error) => {
      console.error("Login failed:", error);
      alert("Login failed: " + error.message);
  });
}


function logout() {
  firebase.auth().signOut().then(() => {
      console.log("Logged out successfully");
      document.getElementById("postForm").style.display = "none";
      document.getElementById("logoutBtn").style.display = "none";
  }).catch((error) => {
      console.error("Logout failed:", error);
  });
}


// Check if user is logged in on page load
auth.onAuthStateChanged((user) => {
    if (user) {
        document.getElementById("postForm").style.display = "block";
        document.getElementById("logoutBtn").style.display = "block";
    } else {
        document.getElementById("postForm").style.display = "none";
        document.getElementById("logoutBtn").style.display = "none";
    }
});

// Function to add a new post (only available after login)
function addPost() {
    let title = document.getElementById("title").value;
    let content = document.getElementById("content").value;

    if (title === "" || content === "") {
        alert("Title and content cannot be empty!");
        return;
    }

    db.collection("posts").add({
        title: title,
        content: content,
        timestamp: firebase.firestore.FieldValue.serverTimestamp()
    }).then(() => {
        document.getElementById("title").value = "";
        document.getElementById("content").value = "";
        loadPosts();
    });
}

// Function to load posts into the blog layout
function loadPosts() {
    let postsContainer = document.querySelector(".leftcolumn");
    postsContainer.innerHTML = ""; // Clear old posts

    db.collection("posts").orderBy("timestamp", "desc").get().then((querySnapshot) => {
        querySnapshot.forEach((doc) => {
            let post = doc.data();
            let postElement = document.createElement("div");
            postElement.classList.add("card");
            postElement.innerHTML = `
                <h2>${post.title}</h2>
                <h5>${post.timestamp?.toDate()}</h5>
                <p>${post.content}</p>
            `;
            postsContainer.appendChild(postElement);
        });
    });
}

// Load posts on page load
document.addEventListener("DOMContentLoaded", loadPosts);