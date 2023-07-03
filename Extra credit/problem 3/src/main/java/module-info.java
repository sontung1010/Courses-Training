module com.example.problem3 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;

    opens com.example.problem3 to javafx.fxml;
    exports com.example.problem3;
}