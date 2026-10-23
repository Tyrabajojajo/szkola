import { Component, Input} from "@angular/core";

@Component({
    selector: 'app-users',
    templateUrl: './users.component.html',
    styleUrl: './users.component.css',
    standalone: false
})
export class UsersComponents{
   @Input() usersList: string[] = ['Brak uzytkownikow'];

   
}