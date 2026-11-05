import { NgModule, provideBrowserGlobalErrorListeners } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppRoutingModule } from './app-routing-module';
import { App } from './app';
import { UsersComponents } from './users/users.component';
import { UsersInputComponent } from './users/users-input.component';

@NgModule({
  declarations: [
    App, UsersComponents, UsersInputComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
],
  providers: [
    provideBrowserGlobalErrorListeners(),
  ],
  bootstrap: [App]
})
export class AppModule { }
